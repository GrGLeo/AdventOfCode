#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream inputFile("day3.txt");
  if (!inputFile) {
    std::cerr << "Failed to get input for the day.\n";
    return 1;
  }

  std::string line{};
  char same{};
  int count{};
  while (std::getline(inputFile, line)) {
    int len = line.length();
    int split = len / 2;
    bool found = false;
    std::string packOne = line.substr(0, split);
    std::string packTwo = line.substr(split);

    for (int i = 0; i < split; i++) {
      char left = packOne[i];
      for (int j = 0; j < split; j++) {
        char right = packTwo[j];
        if (left == right) {
          found = true;
          int value = static_cast<int>(left);
          if (value >= 97) {
            value -= 96;
          } else {
            value -= 38;
          }
          count += value;
        }
        if (found) {
          break;
        }
      }
      if (found) {
        break;
      }
    }
  }
  std::cout << count;
  return 0;
}
