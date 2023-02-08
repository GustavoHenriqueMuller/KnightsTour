#include "weighted.h"

#include <algorithm>
#include <map>
#include <iostream>

namespace Weighted {
    Board solve(Board board, const Position& initialPosition) {
        Board weightBoard = buildWeightBoard(BOARD_WIDTH, BOARD_HEIGHT);

        doMovement(board, weightBoard, initialPosition);
        return board;
    }

    Board buildWeightBoard(int width, int height) {
        Board weightBoard;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int i1 = std::min(i, height - i - 1);
                int j1 = std::min(j, width - j - 1);

                weightBoard.set(Position(i, j), std::min(i1, j1));
            }
        }

        return weightBoard;
    }

    void doMovement(Board& board, const Board& weightBoard, const Position& currentPosition) {
        board.moveTo(currentPosition);

        std::vector<Position> movements = getMovements(board, weightBoard, currentPosition);

        for (Position movementPosition : movements) {
            doMovement(board, weightBoard, movementPosition);

            if (board.isSolved()) {
                return;
            } else {
                board.set(movementPosition, 0);
            }
        }
    }

    std::vector<Position> getMovements(Board& board, const Board& weightBoard, const Position& position) {
        std::vector<Position> movements;

        // Add vertical movements.
        movements.push_back(Position(position.i - 1, position.j + 2));
        movements.push_back(Position(position.i - 1, position.j - 2));
        movements.push_back(Position(position.i + 1, position.j + 2));
        movements.push_back(Position(position.i + 1, position.j - 2));

        // Add horizontal movements.
        movements.push_back(Position(position.i - 2, position.j + 1));
        movements.push_back(Position(position.i - 2, position.j - 1));
        movements.push_back(Position(position.i + 2, position.j + 1));
        movements.push_back(Position(position.i + 2, position.j - 1));

        // Remove invalid positions.
        std::vector<Position> possibleMovements;

        for (Position& movement : movements) {
            if (board.isValidPosition(movement)) {
                possibleMovements.push_back(movement);
            }
        }

        // Order positions by lesser weight.
        std::sort(possibleMovements.begin(), possibleMovements.end(), [&weightBoard](const Position& lhs, const Position& rhs) {
           return weightBoard.at(lhs) < weightBoard.at(rhs);
        });

        return possibleMovements;
    }
}
