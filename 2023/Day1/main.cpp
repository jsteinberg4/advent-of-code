/**
 * @file
 * @brief Advent of Code day 1 (https://adventofcode.com/2023/day/1)
 *
 * NOTE: This is the first problem I have ever solved in C++. There will likely
 * be some inefficient code!
 */

#include "day1.hpp"
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
    puzzle1();
    break;
  case 2:
    puzzle2();
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
  }

  input.close();
  return sum;
}

static int puzzle1_line_sum(const std::string &line) {
  std::vector<std::string> nums;

  /* Learner note: auto will become std::string::iterator at *compile* time */
  for (auto iter = line.begin(); iter != line.end(); iter++) {
    if (std::isdigit(*iter))
      nums.push_back(std::string(*iter));
  }
  std::cout << "Numbers: \n";
  for (auto iter = nums.begin(); iter != nums.end(); iter++)
    std::cout << *iter << "\n";
  exit(2);
  //  uint32_t left = 0;
  //  uint32_t right = line.length() - 1;

  //  while (left < line.length()) {
  //    if (std::isdigit(line[left]))
  //      break;
  //    else
  //      left++;
  //  }
  //  while (right > 0) {
  //    if (std::isdigit(line[right]))
  //      break;
  //    else
  //      right++;
  //  }

  //  if (left < right) {
  //    int local_sum = atoi(&line[left]) * 10 + atoi(&line[right]);
  //    /* std::cout << "Line sum=" << local_sum << "\n"; */
  //    if (local_sum > 99) {
  //      std::cout << "Line value adds to > 100"
  //                << "\n";
  //      std::cout << "\tLine: " << line << "\n";
  //      std::cout << "\tleft=" << line[left] << ", right=" << line[right]
  //                << "\n";
  //    }
  //    sum += local_sum;
  //  } else if (left == right)
  //    sum += atoi(&line[left]);
  return 0;
}

int puzzle2() { return -1; }
