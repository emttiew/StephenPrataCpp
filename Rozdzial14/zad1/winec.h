#ifndef WINE_H_
#define WINE_H_

#include "pairs.h"
#include <valarray>

class Wine 
{
private:
    using ArrayInt = std::valarray<int>;
    using PairArray = Pair<ArrayInt, ArrayInt>;
    std::string label;
    PairArray shelf;
    ArrayInt vintage;
    ArrayInt bottles;
    int no_years;
public:
    Wine() : label("brak"), no_years(0), vintage(), bottles(), shelf() {}
    Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), no_years(y), vintage(yr, y), bottles(bot, y) {}
    Wine(const char * l, int y) : label(l), no_years(y), vintage(y), bottles(y) {}
    void GetBottles();
    const std::string & Label() const { return label; }
    const int sum() const;
    void Show() const;
};

#endif