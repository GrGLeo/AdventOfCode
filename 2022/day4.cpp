

#include <fstream>
#include <iostream>
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
  std::ifstream inputFile("day4.txt");
  if (!inputFile) {
    std::cerr << "Failed to read input file.";
    return 1;
  }

  int scores{};
  std::string line;
  
  while (std::getline(inputFile, line)) {
    std::vector results = split(line, ',');
    std::string left = results[0];
    std::string right = results[1];
    std::vector rangeOne = split(left, '-');
    std::vector rangeTwo = split(right, '-');
    int leftOne = std::stoi(rangeOne[0]);
    int leftTwo = std::stoi(rangeOne[1]);
    int rightOne = std::stoi(rangeTwo[0]);
    int rightTwo = std::stoi(rangeTwo[1]);

    std::cout << leftOne << " " << leftTwo << " " << rightOne << " " << rightTwo << std::endl;
    if ((rightOne >= leftOne && rightTwo <= leftTwo) || (leftOne >= rightOne && leftTwo <= rightTwo)) {
      std::cout << "True" << std::endl;
      scores++;
    } else if ((rightOne <= leftTwo) || (leftOne <= rightTwo)) {
      scores++;
    }
  }
  std::cout << scores;
  return 0;
}
