#include "board.h"
#include "bruteforce.h"

#include <iostream>
#include <chrono>

using TimePoint = std::chrono::steady_clock::time_point;

int main() {
    // Initialize board, print board and board size/dimensions.
    Board board = Board();

    std::cout << "Board size: " << BOARD_WIDTH << "x" << BOARD_HEIGHT << " = " << BOARD_SIZE << std::endl;
    board.print();

    // Execute bute force solution and calculate elapsed time.
    TimePoint begin = std::chrono::steady_clock::now();

    Board solution = solveByBruteForce(board, Position(3, 3));
    solution.print();

    TimePoint end = std::chrono::steady_clock::now();

    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " [ms]" << std::endl;
    return 0;
}
