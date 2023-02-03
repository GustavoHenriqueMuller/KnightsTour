#ifndef BOARD_H
#define BOARD_H

#include "position.h"

#include <array>

/*
 * The smallest rectangular board with open knight tours is the 12-cell 3 by 4
 * (three geometrically distinct found by Euler 1759). The smallest rectangular boards
 * with closed knight tours are the 30-cell boards 3 by 10 (the first found by Ernest Bergholt 1918)
 * and 5 by 6 (three solutions, one asymmetric found by Euler 1759, and two symmetric found by others later).
*/

const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;
const int BOARD_SIZE = BOARD_WIDTH * BOARD_HEIGHT;

class Board {
private:
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> data;
    int occupiedPositionsAmount = 0;

public:
    Board();

    int at(Position position);
    bool isVisited(Position position);
    void set(Position position, int value);
    bool isValidPosition(const Position& position);
    bool isSolved();
    int getOccupiedPositionsAmount();
    void print();
};

#endif // BOARD_H
