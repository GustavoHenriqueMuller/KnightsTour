#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "board.h"
#include "position.h"

#include <vector>

Board solveByBruteForce(Board board, const Position& initialPosition);
void doMovement(Board& board, const Position& currentPosition);
std::vector<Position> getMovements(Board& board, const Position& position);

#endif // BRUTEFORCE_H
