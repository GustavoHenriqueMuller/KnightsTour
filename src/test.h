#ifndef TEST_H
#define TEST_H

#include "board.h"

#include <chrono>

#define TEST_BOARD_ROWS BOARD_ROWS
#define TEST_BOARD_COLUMNS BOARD_COLUMNS

using TimePoint = std::chrono::steady_clock::time_point;

namespace Test {
    Board getBruteforceTimes();
    Board getWeightedTimes();
    int getMilliseconds(const TimePoint& begin, const TimePoint& end);
}

#endif // TEST_H
