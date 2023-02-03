#include "position.h"

#include <iostream>

Position::Position(int i, int j) {
    this->i = i;
    this->j = j;
}

void Position::print() const {
    std::cout << "{i: " << this->i << ", j: " << this->j << "}" << std::endl;
}
