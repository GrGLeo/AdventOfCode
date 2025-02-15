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

  std::map<std::string, std::map<std::string, int>> score;
  score["A"]["X"] = 3; 
  score["A"]["Y"] = 4; 
  score["A"]["Z"] = 8; 
  score["B"]["X"] = 1; 
  score["B"]["Y"] = 5; 
  score["B"]["Z"] = 9; 
  score["C"]["X"] = 2; 
  score["C"]["Y"] = 6; 
  score["C"]["Z"] = 7; 

  std::string line;
  int totalScore{};
  int idx{};
  while (std::getline(inputFile, line)) {
    std::vector<std::string> elems = split(line, ' ');
    totalScore += score[elems[0]][elems[1]];
  }
  std::cout << "Final score: " << std::to_string(totalScore);
  return 0;
}
