// stonewt.h -- definicja klasy Stonewt
#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class Stonewt
{
    public:
        enum Mode { STONE, PDS_INT, PDS_DOUBLE };        // składowa stanu
    private:
        enum {Lbs_per_stn = 14};                         // liczba funtów na kamień        
        int stone;                                       // masa w całych kamieniach
        double pds_left;                                 // reszta w funtach
        double pounds;                                   // masa w funtach
        Mode mode;                                       // kamienie, funty, funty z częścią ułamkową
    public:
        Stonewt(double lbs, Mode form = STONE);          // konstruktor dla funtów
        Stonewt(int stn, double lbs, Mode form = STONE); // konstruktor dla kamieni i funtów
        Stonewt();                    // konstruktor domyślny
        ~Stonewt();
        void set_mode(Mode form); // zmiana składowej stanu
        friend Stonewt operator+(const Stonewt & s1, const Stonewt & s2);
        friend Stonewt operator-(const Stonewt & s1, const Stonewt & s2);
        friend Stonewt operator*(const Stonewt s1, const Stonewt & s2);
        friend Stonewt operator*(const Stonewt & s, double d);
        friend Stonewt operator*(double d, const Stonewt & s);        
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & st); // wyświetla masę w odpowiednim formacie
};
#endif

