// kompilować ze stonewt.cpp
#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"


int main()
{
    Stonewt incognito = 275; // inicjalizacja konstruktorem
    Stonewt wolfe(285.7, Stonewt::PDS_INT);    // równoważne instrukcji: Stonewt wolfe = 285.7;
    Stonewt taft(21, 8.1, Stonewt::PDS_DOUBLE);

    cout << "Celebryta ważył " << incognito << endl;    
    cout << "Detektyw ważył " << wolfe << endl;
    cout << "Prezydent ważył " << taft << endl;
    
    incognito = 276.8;   // konwersja konstruktorem
    taft = 325;          // równoważne instrukcji: taft = Stonewt(325);
    cout << "Po dodaniu celebryty i detektywa " << incognito + wolfe << endl;    
    cout << "Po przemnożeniu detektywa i prezydenta " << taft * wolfe << endl;  
    cout << "Po przemnożeniu detektywa przez 2 " << 2 * wolfe << endl;    
    cout << "Po przemnożeniu detektywa przez 4 " << wolfe * 4 << endl;
    cout << "Po odjęciu detektywa od celebryty " << incognito - wolfe << endl;
    cout << "Detektyw w kamieniach ";
    wolfe.set_mode(Stonewt::STONE);
    cout << wolfe << endl;

    return 0;
}




