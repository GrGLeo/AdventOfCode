#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

int main() {
  std::ifstream inputFile("day3.txt");
  if (!inputFile) {
    std::cerr << "Failed to get input for the day.\n";
    return 1;
  }

  std::string line{};
  char same{};
  int count{};
  int idx = 0;
  std::vector<std::string> group;
  std::map<char, int> mapOne;
  std::map<char, int> mapTwo;
  while (std::getline(inputFile, line)) {
    group.push_back(line);
    idx++;

    if (idx == 3) {
      std::unordered_set<char> oneSet(group[0].begin(), group[0].end());
      std::unordered_set<char> twoSet(group[1].begin(), group[1].end());

      for (int i = 0; i < group[2].length(); i++) {
        char item = group[2][i];
        if (oneSet.find(item) != oneSet.end() &&
            twoSet.find(item) != twoSet.end()) {
          int value = static_cast<int>(item);
          if (value >= 97) {
            value -= 96;
          } else {
            value -= 38;
          }
          count += value;
          break;
        }
      }
      idx = 0;
      group.clear();
    }
  }
  std::cout << count;
  return 0;
}
