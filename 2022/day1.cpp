#include <fstream>
#include <iostream>
int main() {

  std::ifstream inputFile("day1.txt");
  if (!inputFile) {
    std::cout << "Error reading puzzles of the day.\n";
  }

  int max = 0;
  int calories{};
  std::string line;

  while (std::getline(inputFile, line)) {
    int calorie{};
    try {
      calorie = std::stoi(line);
      calories += calorie;

    } catch (const std::invalid_argument& e) {
      if (calories >= max) {
        std::cout << std::to_string(calories) << "\n";
        max = calories;
      }
      calories = 0;
    }
  }
  std::cout << std::to_string(calories);
  return 0;
}
