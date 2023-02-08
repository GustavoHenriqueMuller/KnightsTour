#include "board.h"

#include <algorithm>
#include <map>

namespace Weighted {
    Board solve(Board board, const Position& initialPosition);
    Board buildWeightBoard(int width, int height);
    void doMovement(Board& board, const Board& weightBoard, const Position& currentPosition);
    std::vector<Position> getMovements(Board& board, const Board& weightBoard, const Position& position);
}
