"""
Sanity checking puzzle 1 strategy w/ a python implementation
"""

from typing import List


INPUT_FILE = "input1.txt"


def load_input() -> List[str]:
    with open(INPUT_FILE, "r", encoding="utf-8") as file:
        return [line.strip() for line in file]


def line_value(line: str) -> int:
    first = -1
    last = -1

    for c in line:
        if c.isdigit():
            if first == -1:
                first = int(c) * 10
            else:
                last = int(c)

    first = max(first, 0)
    last = max(last, 0)

    return first + last


def puzzle1():
    calibration_values = load_input()

    return sum(map(line_value, calibration_values))


if __name__ == "__main__":
    puzzle_sum = puzzle1()
    print(f"Sum: {puzzle_sum}")
