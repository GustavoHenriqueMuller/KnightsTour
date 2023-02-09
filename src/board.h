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

const int BOARD_ROWS = 5;
const int BOARD_COLUMNS = 6;
const int BOARD_SIZE = BOARD_ROWS * BOARD_COLUMNS;

class Board {
private:
    std::array<std::array<int, BOARD_COLUMNS>, BOARD_ROWS> data;
    int occupiedPositionsAmount = 0;

public:
    Board();

    int at(const Position& position) const;
    bool isVisited(const Position& position) const;
    void moveTo(const Position& position);
    void set(const Position& position, int value);
    bool isValidPosition(const Position& position) const;
    bool isSolved() const;
    int getOccupiedPositionsAmount() const;
    void print() const;
};

#endif // BOARD_H
