#ifndef BADDUDE_HPP_
#define BADDUDE_HPP_

#include "Gunslinger.hpp"
#include "PokerPlayer.hpp"

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() : Gunslinger(), PokerPlayer() {}
    BadDude(char * fullname, double draw_time, char * color, int cuts) : Gunslinger(fullname, draw_time, cuts), PokerPlayer(fullname, color) {}
    const double GDraw() const;
    const Card & CDraw() const;
    virtual void Show() const;
    void Set();
    ~BadDude();
};

const double BadDude::GDraw() const 
{
    Gunslinger::Draw();
}

const Card & BadDude::CDraw() const
{
    PokerPlayer::Draw();
}

void BadDude::Show() const
{
    Person::Show();
    Gunslinger::ShowComponents();
    PokerPlayer::ShowComponents();    
}

void BadDude::Set()
{
    Person::Set();
    Gunslinger::SetComponents();
    PokerPlayer::SetComponents();
}

#endif