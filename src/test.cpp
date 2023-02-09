#include "test.h"
#include "bruteforce.h"
#include "weighted.h"

#include <iostream>

namespace Test {
    Board getBruteforceTimes() {
        Board times;

        for (int i = 0; i < TEST_BOARD_ROWS; i++) {
            for (int j = 0; j < TEST_BOARD_COLUMNS; j++) {
                std::cout << "Executing bruteforce at position (" << i << ", " << j << ")... ";

                Board board = Board();

                TimePoint begin = std::chrono::steady_clock::now();
                Bruteforce::solve(board, Position(i, j));
                TimePoint end = std::chrono::steady_clock::now();

                int milliseconds = getMilliseconds(begin, end);
                times.set(Position(i, j), milliseconds);

                std::cout << milliseconds << " [ms]" << std::endl;
            }
        }

        return times;
    }

    Board getWeightedTimes() {
        Board times;

        for (int i = 0; i < TEST_BOARD_ROWS; i++) {
            for (int j = 0; j < TEST_BOARD_COLUMNS; j++) {
                std::cout << "Executing weighted at position (" << i << ", " << j << ")... ";

                Board board = Board();

                TimePoint begin = std::chrono::steady_clock::now();
                Weighted::solve(board, Position(i, j));
                TimePoint end = std::chrono::steady_clock::now();

                int milliseconds = getMilliseconds(begin, end);
                times.set(Position(i, j), milliseconds);

                std::cout << milliseconds << " [ms]" << std::endl;
            }
        }

        return times;
    }

    int getMilliseconds(const TimePoint& begin, const TimePoint& end) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
}


