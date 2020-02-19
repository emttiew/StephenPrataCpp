#include "move.h"
#include <iostream>

Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;    
}

Move Move::add(const Move & m) const
{
    Move sum((m.x + this->x), (m.y + this->y));
    return sum;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}