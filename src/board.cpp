#include "board.h"

#include <iostream>

Board::Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            this->data[i][j] = 0;
        }
    }
}

int Board::at(const Position& position) const {
    return this->data[position.i][position.j];
}

bool Board::isVisited(const Position& position) const {
    return this->at(position) != 0;
}

void Board::moveTo(const Position& position) {
    this->set(position, this->getOccupiedPositionsAmount() + 1);
}

void Board::set(const Position& position, int value) {
    int oldValue = this->data[position.i][position.j];

    if (value == 0 && oldValue != 0) {
        this->occupiedPositionsAmount--;
    } else if (value != 0 && oldValue == 0) {
        this->occupiedPositionsAmount++;
    }

    this->data[position.i][position.j] = value;
}

bool Board::isValidPosition(const Position& position) const {
    bool isOutOfBounds = (position.i < 0 || position.i >= BOARD_HEIGHT) || (position.j < 0 || position.j >= BOARD_WIDTH);

    if (isOutOfBounds) {
        return false;
    }

    return !this->isVisited(position);
}

bool Board::isSolved() const {
    return this->occupiedPositionsAmount == BOARD_SIZE;
}

int Board::getOccupiedPositionsAmount() const {
    return this->occupiedPositionsAmount;
}

void Board::print() const {
    for (int i = 0 ; i < BOARD_HEIGHT; i++) {
        std::cout << "[";

        for (int j = 0 ; j < BOARD_WIDTH; j++) {
            int value = this->data[i][j];

            if (value < 10) {
                std::cout << " ";
            }

            std::cout << this->data[i][j];

            if (j < BOARD_WIDTH - 1) {
                std::cout << ", ";
            }
        }

        std::cout << "]" << std::endl;
    }

    std::cout << std::endl;
}
