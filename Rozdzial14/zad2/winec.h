#ifndef WINE_H_
#define WINE_H_

#include "pairs.h"
#include <valarray>

class Wine : private std::string, private std::valarray<int>
{
private:
    using ArrayInt = std::valarray<int>;
    using PairArray = Pair<ArrayInt, ArrayInt>;    
    PairArray shelf;    
    int no_years;
public:
    Wine() : std::string("brak"), no_years(0), shelf(ArrayInt(), ArrayInt()) {}
    Wine(const char * l, int y, const int yr[], const int bot[]) : std::string(l), no_years(y), shelf(ArrayInt(yr, y), ArrayInt(bot, y)) {}
    Wine(const char * l, int y) : std::string(l), no_years(y), shelf(ArrayInt(y), ArrayInt(y)) {}
    void GetBottles();
    const std::string & Label() const { return (const std::string &) *this; }
    const int sum() const;
    void Show() const;
};

#endif