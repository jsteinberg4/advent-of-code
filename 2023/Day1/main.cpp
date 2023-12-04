/**
 * @file
 * @brief Advent of Code day 1 (https://adventofcode.com/2023/day/1)
 */

#include "day1.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./day1 [puzzle1, puzzle2]"
              << "\n";
    std::exit(1);
  }

  return 0;
}

int puzzle1() {
  // 1) Get file descriptor for file
  // For each line in file
  // -> Save first, last appearing number
  // -> Convert str->int. Multiply first by 10, add to last (no larger than 99)
  // Sum
  return 0;
}
