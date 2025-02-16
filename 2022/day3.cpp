#include <fstream>
#include <iostream>
#include <map>
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
    std::map<char, int> packMap;

    for (int i = 0; i < split; i++) {
      char item = packOne[i];
      int value = static_cast<int>(item);
      if (value >= 97) {
        value -= 96;
      } else {
        value -= 38;
      }
      packMap[item] = value;
    }

    for (int i = 0; i < split; i++) {
      char item = packTwo[i];
      if (packMap.find(item) != packMap.end()) {
        count += packMap[item];
        found = true;
        break;
      } 
    }
  }
  std::cout << count;
  return 0;
}
