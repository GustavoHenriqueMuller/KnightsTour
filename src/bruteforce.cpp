#include "bruteforce.h"

#include <algorithm>

namespace Bruteforce {
    Board solve(Board board, const Position& initialPosition) {
        doMovement(board, initialPosition);
        return board;
    }

    void doMovement(Board& board, const Position& currentPosition) {
        board.moveTo(currentPosition);

        std::vector<Position> movements = getMovements(board, currentPosition);

        for (Position movementPosition : movements) {
            doMovement(board, movementPosition);

            if (board.isSolved()) {
                return;
            } else {
                board.set(movementPosition, 0);
            }
        }
    }

    std::vector<Position> getMovements(Board& board, const Position& position) {
        std::vector<Position> movements;

        // Add horizontal movements.
        /*movements.push_back(Position(position.i - 1, position.j + 2));
        movements.push_back(Position(position.i - 1, position.j - 2));
        movements.push_back(Position(position.i + 1, position.j + 2));
        movements.push_back(Position(position.i + 1, position.j - 2));

        // Add vertical movements.
        movements.push_back(Position(position.i - 2, position.j + 1));
        movements.push_back(Position(position.i - 2, position.j - 1));
        movements.push_back(Position(position.i + 2, position.j + 1));
        movements.push_back(Position(position.i + 2, position.j - 1));*/

        movements.push_back(Position(position.i - 1, position.j + 2));
        movements.push_back(Position(position.i + 1, position.j + 2));
        movements.push_back(Position(position.i - 2, position.j + 1));
        movements.push_back(Position(position.i - 2, position.j - 1));
        movements.push_back(Position(position.i - 1, position.j - 2));
        movements.push_back(Position(position.i + 1, position.j - 2));
        movements.push_back(Position(position.i + 2, position.j - 1));
        movements.push_back(Position(position.i + 2, position.j + 1));

        // Remove invalid positions.
        std::vector<Position> possibleMovements;

        for (Position& movement : movements) {
            if (board.isValidPosition(movement)) {
                possibleMovements.push_back(movement);
            }
        }

        return possibleMovements;
    }
}
