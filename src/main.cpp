#include "board.h"
#include "bruteforce.h"
#include "weighted.h"

#include <iostream>
#include <chrono>

using TimePoint = std::chrono::steady_clock::time_point;

void printBruteForceAndWeightedTimes(const Board& board) {
    Board bruteforceTimes;
    Board weightedTimes;

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            TimePoint begin, end;

            // Bruteforce algorithm.
            begin = std::chrono::steady_clock::now();
            Bruteforce::solve(board, Position(i, j));
            end = std::chrono::steady_clock::now();

            int bruteforceMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            bruteforceTimes.set(Position(i, j), bruteforceMilliseconds);

            // Weighted algorithm.
            begin = std::chrono::steady_clock::now();
            Weighted::solve(board, Position(i, j));
            end = std::chrono::steady_clock::now();

            int weightedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            weightedTimes.set(Position(i, j), weightedMilliseconds);
        }
    }

    bruteforceTimes.print();
    weightedTimes.print();
}

int main() {
    // Initialize board, print board and board size/dimensions.
    Board board = Board();

    std::cout << "Board size: " << BOARD_WIDTH << "x" << BOARD_HEIGHT << " = " << BOARD_SIZE << std::endl;
    board.print();

    // Execute brute force solution and calculate elapsed time.
    printBruteForceAndWeightedTimes(board);

    return 0;
}
