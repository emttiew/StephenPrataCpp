#ifndef POKERPLAYER_HPP_
#define POKERPLAYER_HPP_

#include "Person.hpp"

class Card
{
private:
    std::string color;
    int number;
public:
    Card(std::string c) : color(c), number(rand()%52) {}
    Card();
    friend std::ostream & operator<<(std::ostream & os, const Card & cd);
};

class PokerPlayer : virtual public Person
{
private:    
    Card card;
public:
    PokerPlayer() : Person(), card() {}
    PokerPlayer(char * fullname, char * card_color) : Person(fullname), card(card_color) {}
    const Card & Draw() const { return card; }
    virtual void Show() const;
};

std::ostream & operator<<(std::ostream & os, const Card & cd)
{
    os << "Kolor: " << cd.color << "\n";
    os << "Numer: " << cd.number;
}

void PokerPlayer::Show() const
{
    Person::Show();
    std::cout << "Karta:\n" << card << "\n"; 
}

#endif