#ifndef POSITION_H
#define POSITION_H

struct Position {
public:
    int i;
    int j;

    Position(int i, int j);
    void print() const;
};

#endif // POSITION_H
