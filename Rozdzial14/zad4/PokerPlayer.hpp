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
    std::string color;
    Card card;
public:
    PokerPlayer() : Person(), card(), color() {}
    PokerPlayer(char * fullname, char * card_color) : Person(fullname), color(card_color), card(color) {}
    const Card & Draw() const { return card; }
    virtual void Show() const;
    void ShowComponents() const;
    void Set();
    void SetComponents();
    ~PokerPlayer();
};

std::ostream & operator<<(std::ostream & os, const Card & cd)
{
    os << "Kolor: " << cd.color << "\n";
    os << "Numer: " << cd.number;
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
    std::cout << "Podaj kolor karty: \n";
    getline(std::cin, color);    
}

void PokerPlayer::SetComponents()
{
    std::cout << "Podaj kolor karty: \n";
    getline(std::cin, color);
}

#endif