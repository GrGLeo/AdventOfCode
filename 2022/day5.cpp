#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
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
class Stack {
private:
  static const int MAX = 1000;
  char arr[MAX];
  int top;

public:
  Stack() : top(-1) {};

  void push(char x) {
    if (top >= MAX) {
      throw std::overflow_error("Stack overflow");
    }
    arr[++top] = x;
  }

  char pop() {
    if (top < 0) {
      throw std::underflow_error("Stack underflow");
    }
    return arr[top--];
  }

  char peek() const {
    if (top < 0) {
      throw std::underflow_error("Stack is empty");
    }
    return arr[top];
  }

  bool isEmpty() const { return top < 0; }

  int length() const { return top; }
};

int main() {
  std::map<char, Stack> stackMap;
  std::map<char, std::string> initStack;
  initStack['1'] = "SMRNWJVT";
  initStack['2'] = "BWDJQPCV";
  initStack['3'] = "BJFHDRP";
  initStack['4'] = "FRPBMND";
  initStack['5'] = "HVRPTB";
  initStack['6'] = "CBPT";
  initStack['7'] = "BJRPL";
  initStack['8'] = "NCSLTZBW";
  initStack['9'] = "LSG";

  for (const auto &pair : initStack) {
    for (char ch : pair.second) {
      stackMap[pair.first].push(ch);
    }
  }

  std::ifstream inputFile("day5.txt");
  if (!inputFile) {
    std::cerr << "Failed to read input file" << std::endl;
    return 1;
  }

  std::string line{};
  while (std::getline(inputFile, line)) {
    std::vector results = split(line, ' ');
    int numberMvt = std::stoi(results[1]);
    char from = results[3][0];
    char to = results[5][0];
    for (int i = 0; i < numberMvt; i++) {
      char out = stackMap[from].pop();
      stackMap[to].push(out);
    }
  }

  for (const auto &pair : stackMap) {
    std::cout << pair.second.peek();
  }
  std::cout << std::endl;

  return 0;
}
