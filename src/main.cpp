#include "board.h"
#include "test.h"

#include <iostream>
#include <chrono>

int main() {
    // Initialize board, print board and board size/dimensions.
    std::cout << "Board size: " << BOARD_WIDTH << "x" << BOARD_HEIGHT << " = " << BOARD_SIZE << std::endl << std::endl;

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

    int bruteforceTotalTime = Test::getSeconds(bruteforceStart, bruteforceEnd);
    int weightedTotalTime = Test::getSeconds(weightedStart, weightedEnd);

    // Print bruteforce times.
    std::cout << "Bruteforce times [s]:" << std::endl;
    bruteforceTimes.print();
    std::cout << std::endl << "Total bruteforce time [s]: " << bruteforceTotalTime << std::endl << std::endl;

    // Print weighted times.
    std::cout << "Weighted times [ms]:" << std::endl;
    weightedTimes.print();
    std::cout << std::endl << "Total weighted time [s]: " << weightedTotalTime << std::endl << std::endl;

    return 0;
}
