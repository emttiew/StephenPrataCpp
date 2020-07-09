#ifndef POKERPLAYER_HPP_
#define POKERPLAYER_HPP_

#include "Person.hpp"
#include <stdlib.h>
#include <time.h>

class Card
{
private:
    std::string available_colors[4] = {"karo", "kier", "trefl", "pik"};
    std::string color;
    int number;
public:   
    Card();
    friend std::ostream & operator<<(std::ostream & os, const Card & cd);    
    ~Card() {}
};

class PokerPlayer : virtual public Person
{
private:    
    std::string color;
    Card card;
public:
    PokerPlayer() : Person(), card(), color() {}
    PokerPlayer(char * fullname, char * card_color) : Person(fullname), color(card_color), card() {}
    const Card & Draw() const { return card; }
    virtual void Show() const;
    void ShowComponents() const;
    void Set();   
    ~PokerPlayer() {}
};

Card::Card()
{
    srand (time(NULL));
    number = rand() % 52 + 1; 
    color = available_colors[rand()%4];    
}

std::ostream & operator<<(std::ostream & os, const Card & cd)
{
    os << "\tKolor: " << cd.color << "\n";
    os << "\tNumer: " << cd.number;
}
void PokerPlayer::ShowComponents() const
{   
    std::cout << "Karta:\n" << card << "\n";
}

void PokerPlayer::Show() const
{
    Person::Show();
    std::cout << "Karta:\n" << card << "\n"; 
}

void PokerPlayer::Set()
{
    Person::Set();   
}



#endif