#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

template <typename Out>
void split(const std::string &s, char delim, Out result) {
  std::istringstream iss(s);
  std::string item;
  while (std::getline(iss, item, delim)) {
    *result++ = item;
  }
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

int main() {
  std::ifstream inputFile("day2.txt");
  if (!inputFile) {
    std::cerr << "Failed to read text input";
    return 1;
  }

  int score{};
  std::map<std::string, std::string> mapItem;
  mapItem["A"] = "rock";
  mapItem["B"] = "paper";
  mapItem["C"] = "scissor";
  mapItem["X"] = "rock";
  mapItem["Y"] = "paper";
  mapItem["Z"] = "scissor";

  std::map<std::string, int> mapScore;
  mapScore["rock"] = 1;
  mapScore["paper"] = 2;
  mapScore["scissor"] = 3;

  std::string line;
  int idx{};
  while (std::getline(inputFile, line)) {
    std::vector<std::string> elems = split(line, ' ');
    std::string pOne = mapItem[elems[0]];
    std::string pTwo = mapItem[elems[1]];
    idx++;
    std::cout << std::to_string(idx) << "\n";
    if (pOne == pTwo) {
      score += mapScore[pTwo] + 3;
    } else {
      if (pOne == "rock") {
        if (pTwo == "paper") {
          score += 8;
        } else if (pTwo == "scissor") {
          score += 3;
        }
      } else if (pOne == "paper") {
        if (pTwo == "rock") {
          score += 1;
        } else if (pTwo == "scissor") {
          score += 9;
        }
      } else {
        if (pTwo == "rock") {
          score += 7;
        } else if (pTwo == "paper") {
          score += 2;
        }
      }
    }
  }
  std::cout << "Final score: " << std::to_string(score);
  return 0;
}
