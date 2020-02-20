#ifndef MOVE_H_
#define MOVE_H_

class Move
{
 private:
    double x;
    double y;
 public:
    Move(double a = 0, double b = 0); // ustawia x na a, y na b
    void showmove() const;            // wyświetla bieżące wartości x i y
    Move add(const Move & m) const;   
    // powyższa metoda sumuje x obiektu m i x obiektu wywołującego,
    // y obiektu m i y obiektu wywołującego, tworzy nowy obiekt, inicjalizuje
    // go obliczonymi sumami x i y i zwraca tak zainicjalizowany obiekt
    void reset(double a = 0, double b = 0); // ustawia x na a, y na b
};

#endif