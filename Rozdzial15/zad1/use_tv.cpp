//use_tv.cpp -- używa klas Tv oraz Remote
#include <iostream>
#include "tv.h"

int main()
{
    using std::cout;
    Tv s42;
    cout << "Początkowe ustawienia telewizora 42\":\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout << "\nNowe ustawienia telewizora 42\":\n";
    s42.settings();

    Remote grey;

    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    cout << "\nUstawienia telewizora 42\" po użyciu pilota:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\nUstawienia telewizora 58\"\n";
    s58.settings();

    cout << "Wyłączam telewizor 58...\n";
    grey.onoff(s58);
    if(!(s58.ison()))
        cout << "S58: Wyłączony***\n";
    cout << "Tryb pilota: " << grey.show_interactive_mode() << '\n';
    cout << "Próbuję zmienić tryb pilota: \n";
    if(s58.change_remote_mode(grey))
    {
        cout << "Tryb pilota: " << grey.show_interactive_mode() << '\n';
    } else {
        cout << "Próba zmiany na wyłączonym telewizorze nie powiodła się. Włączam telewizor...\n";
        grey.onoff(s58);
        cout << "Zmieniam tryb...\n";
        s58.change_remote_mode(grey);
        cout << "Tryb pilota: " << grey.show_interactive_mode() << '\n';
    }

    return 0;
}

