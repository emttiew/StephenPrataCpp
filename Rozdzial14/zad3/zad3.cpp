#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queue.h"

const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTp<Worker *> lolas(SIZE);     
    Worker * worker;
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Podaj kategorię pracownika:\n"
            << "k: kelner  p:piosenkarz  "
            << "s: śpiewający kelner  w:wyjście\n";
        cin >> choice;
        while (strchr("kpsw", choice) == NULL)
        {
            cout << "Wpisz k, p, s lub w: ";
            cin >> choice;
        }
        if (choice == 'w')
            break;
        switch(choice)
        {
            case 'k': worker = new Waiter;
                      break;
            case 'p': worker = new Singer;
                      break;
            case 's': worker = new SingingWaiter;
                      break;
        }
        cin.get();
        worker->Set();
        lolas.enqueue(worker);
    }

    cout << "\nLista pracowników:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas.dequeue(worker);
        worker->Show();        
        delete worker;
    }    
    cout << "Koniec.\n";
    return 0;
}

