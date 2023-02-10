#include "test.h"
#include "bruteforce.h"
#include "weighted.h"

#include <iostream>

namespace Test {
    void runBruteforce(const Position& position) {
        Board board = Board();

        TimePoint start = std::chrono::steady_clock::now();
        Board solution = Bruteforce::solve(board, position);
        TimePoint end = std::chrono::steady_clock::now();

        int milliseconds = getMilliseconds(start, end);

        // Print metrics.
        solution.print();
        std::cout << "Time: " << milliseconds << " [ms]." << std::endl;
    }

    void runWeighted(const Position& position) {
        Board board = Board();

        TimePoint start = std::chrono::steady_clock::now();
        Board solution = Weighted::solve(board, position);
        TimePoint end = std::chrono::steady_clock::now();

        int milliseconds = getMilliseconds(start, end);

        // Print metrics.
        solution.print();
        std::cout << "Time: " << milliseconds << " [ms]." << std::endl;
    }

    void runAllTests() {
        // Execute brute force and weighted algorithms and calculate elapsed time.
        TimePoint bruteforceStart, bruteforceEnd;
        TimePoint weightedStart, weightedEnd;

        bruteforceStart = std::chrono::steady_clock::now();
        Board bruteforceTimes = Test::getBruteforceTimes();
        bruteforceEnd = std::chrono::steady_clock::now();

        weightedStart = std::chrono::steady_clock::now();
        Board weightedTimes = Test::getWeightedTimes();
        weightedEnd = std::chrono::steady_clock::now();

        std::cout << std::endl;

        int bruteforceTotalTime = Test::getMilliseconds(bruteforceStart, bruteforceEnd);
        int weightedTotalTime = Test::getMilliseconds(weightedStart, weightedEnd);

        // Print bruteforce times.
        std::cout << "Bruteforce times [ms]:" << std::endl;
        bruteforceTimes.print();
        std::cout << std::endl << "Total bruteforce time [ms]: " << bruteforceTotalTime << std::endl << std::endl;

        // Print weighted times.
        std::cout << "Weighted times [ms]:" << std::endl;
        weightedTimes.print();
        std::cout << std::endl << "Total weighted time [ms]: " << weightedTotalTime << std::endl << std::endl;

    }

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


