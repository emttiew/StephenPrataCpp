#include <iostream>

#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);    // czy dotarł już następny klient?

int main ()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    cout << "Studium przypadku: bankomat Banku Stu Kas\n";
    cout << "Podaj maksymalną długość kolejki: ";
    int qs;
    cin >> qs;
    Queue line(qs);            // w kolejce może stanąć do qs klientów

    cout << "Podaj symulowany czas (w godzinach): ";
    int hours;                 // liczba godzin symulacji
    cin >> hours;
    // symulacja z jednominutową rozdzielczością
    long cyclelimit = MIN_PER_HR * hours;       // liczba cykli

    Item temp;                 // dane nowego klienta
    double perhour;            // średnia liczba nowych klientów na godzinę
    long turnaways = 0;        // liczba klientów odesłanych z kolejki
    long customers = 0;        // liczba klientów przyjętych do kolejki
    long served = 0;           // liczba klientów obsłużonych w symulacji
    long sum_line = 0;         // łączna liczba oczekujących
    int wait_time = 0;         // czas do zwolnienia bankomatu
    long line_wait = 0;        // łączny czas oczekiwania
    long average_wait_time = (double) line_wait / served;
    double min_per_cust;       // średni odstęp czasowy pomiędzy klientami
    min_per_cust = MIN_PER_HR / perhour;

    // rozpoczęcie symulacji
    int i = 60;
    do
	{
	    perhour = i--;	
	    Queue line(hours * perhour);		
		 min_per_cust = MIN_PER_HR / perhour;
		 turnaways = 0;		
		 customers = 0;     
		 served = 0;        
		 sum_line = 0;     
		 wait_time = 0;     
		 line_wait = 0;    

	// rozpoczęcie symulacji
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // mamy nowego chętnego
        {
            if (line.isfull() && (double) line_wait / served > 1.0)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);        // czas przybycia = nr cyklu
                line.enqueue(temp);     // dołączenie klienta do kolejki
            }
        }
        if (wait_time <= 0 && !line.isempty())
        {
            line.dequeue (temp);        // następny do obsłużenia
            wait_time = temp.ptime();   // czas obsługi = wait_time
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();        
    }

	    line.~Queue();
	}
	while ((double) line_wait / served > 1.0);
    i++;

    if (customers > 0)
    {
        cout << "liczba klientów na godzinę: " << i << endl;
        cout << " liczba klientów przyjętych: " << customers << endl;
        cout << "liczba klientów obsłużonych: " << served << endl;
        cout << " liczba klientów odesłanych: " << turnaways << endl;
        cout << "    średnia długość kolejki: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
            cout << (double) sum_line / cyclelimit << endl;
        cout << "    średni czas oczekiwania: "
            << (double) line_wait / served << " minut\n";
    }
    else
        cout << "Brak klientów!\n";

    cout << "Gotowe!\n";

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}