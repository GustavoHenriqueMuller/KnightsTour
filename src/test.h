#ifndef TEST_H
#define TEST_H

#include "board.h"

#include <chrono>

#define TEST_BOARD_WIDTH 2
#define TEST_BOARD_HEIGHT 2

using TimePoint = std::chrono::steady_clock::time_point;

namespace Test {
    Board getBruteforceTimes();
    Board getWeightedTimes();
    int getSeconds(const TimePoint& begin, const TimePoint& end);
}

#endif // TEST_H
