/**
 * @file
 * @brief Advent of Code day 1 (https://adventofcode.com/2023/day/1)
 *
 * NOTE: This is the first problem I have ever solved in C++. There will likely
 * be some inefficient code!
 */

#include "day1.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: ./day1 [puzzle1, puzzle2]"
              << "\n";
    std::exit(1);
  }

  int puzzle = std::stoi(argv[1]);
  switch (puzzle) {
  case 1:
    std::cout << "Puzzle 1: " << puzzle1() << "\n";
    break;
  case 2:
    std::cout << "Puzzle 2: " << puzzle2() << "\n";
    break;
  default:
    std::cerr << "Puzzle must be either 1 or 2, received=" << puzzle << "\n";
    std::exit(1);
  }

  return 0;
}

static int puzzle1_line_sum(const std::string &line);
int puzzle1() {
  std::ifstream input(PUZZLE1_INPUT);
  std::string line;
  uint32_t sum = 0;

  if (!input.is_open()) {
    std::cerr << "Unable to open file: " PUZZLE1_INPUT << "\n";
    return -1;
  }

  /* Sum the calibration value for each line */
  while (std::getline(input, line)) {
    sum += puzzle1_line_sum(line);
    /* std::cout << "Sum = " << sum << "\n"; */
  }

  input.close();
  return sum;
}

static int puzzle1_line_sum(const std::string &line) {
  int first = -1;
  int last = -1;

  for (int x = 0; x < line.size(); x++) {
    if (std::isdigit(line[x])) {
      int c_value = line[x] - '0';
      if (first == -1)
        first = c_value * 10;
      else
        last = c_value;
    }
  }

  first = std::max(first, 0);
  last = std::max(last, 0);

  return first + last;
}

int puzzle2() { return -1; }
