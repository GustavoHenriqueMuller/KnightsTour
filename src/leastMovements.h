#ifndef LEASTMOVEMENTS_H
#define LEASTMOVEMENTS_H

#include "board.h"

#include <vector>

namespace Weighted {
    Board solve(Board board, const Position& initialPosition);
    void doMovement(Board& board, const Position& currentPosition);
    std::vector<Position> getMovements(Board& board, const Position& position);
}

#endif // LEASTMOVEMENTS_H
