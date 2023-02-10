#include "board.h"
#include "test.h"

#include <iostream>
#include <chrono>

int main() {
    // Initialize board, print board and board size/dimensions.
    std::cout << "Board size: " << BOARD_ROWS << "x" << BOARD_COLUMNS << " = " << BOARD_SIZE << std::endl << std::endl;
    Test::runWeighted(Position(0, 0));

    return 0;
}
