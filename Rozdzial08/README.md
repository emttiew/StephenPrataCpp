# StephenPrataCpp Rozdział 08 - Polecenia: 

 
1. Napisz funkcję, która normalnie pobiera jeden parametr, adres łańcucha, po czym zaraz pokazuje
ten łańcuch. Jeśli jednak podany zostanie niezerowy drugi parametr, napis ma się pojawić tyle
razy, ile razy dotąd wywołano tę funkcję. Zauważmy, że drugi parametr nie mówi, ile razy należy
pokazać napis. Owszem, funkcja jest nieco bzdurna, ale jej napisanie będzie dobrym ćwiczeniem
utrwalającym wiedzę. Użyj opisanej funkcji w prostym programie, który pokaże jej działanie.

2. Struktura Batonik ma trzy pola: markę producenta, wagę (z częścią ułamkową) oraz liczbę kalorii
(calłkowitoliczbowo). Napisz program korzystający z funkcji, której parametry to referencja
do typu Batonik, wskaźnik do typu char, wartość double oraz wartość int; funkcja ma używać
ostatnich trzech wartości do ustawienia odpowiednich pól struktury. Ostatnie trzy parametry
mają mieć wartości domyślne "Millennium Munch", 2,85 i 350. Poza tym program powinien
korzystać z funkcji pobierającej referencję do Batonika i wyświetlającej zawartość struktury.
Należy użyć w miarę potrzeb const.

3. Napisz funkcję pobierającą referencję do obiektu string jako parametr i zamieniającą zawartość
tego łańcucha na wielkie litery. Użyj funkcji toupper() opisanej w tabeli 6.4. Napisz program,
który w pętli pozwoli przećwiczyć wprowadzanie danych do tej funkcji. Oto wynik przykładowego
uruchomienia tego kodu:
```
Podaj tańcuch (q, aby skończyć): odejdź stąd
ODEJDŹ STĄD
Następny tańcuch (q, aby skończyć) : niezły pasztet!
NIEZŁY PASZTET!
Następny łańcuch (q, aby skofńczyć): q
Do widzenia
```

4. Oto szkielet pewnego programu:

```c++
#include <iostream>
using namespace std;
#include <cstring>
struct stringy { 
	char * str;
	int ct;
};

//tutaj protorypy set(), show(), show()
{
	stringy beany;
	char testing[] = "Rzeczywistość to już nie to , co kiedyś";
	
	set(beany, testing); //pierwszy parametr jako referencja
		//alokacja pamięcia na wynik sprawdzania
		//ustawianie pola str struktury beany, tak by wskazywała nowy blok
		//kopiowanie testing do nowego bloku
		//ustawienie pola ct zmiennej beany
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Gotowe!");
	return 0;
}
```

Uzupełnij powyższy szkielet, definiując opisane funkcje i dodając im prototypy. Zauważmy,
że potrzebne są dwie funkcje show(), obie z parametrami domyślnymi. W razie potrzeby użyj
parametrów const. Zauważmy, że set () powinno korzystać z new do zaalokowania pamięci na
łańcuch. Użyte tutaj techniki są podobne jak w przypadku projektowania i implementacji klas
(w niektórych kompilatorach konieczna może być zmiana nazw plików nagłówkowych
i usunięcie dyrektywy using).

5. Napisz szablon funkcji max5 () pobierającej jako parametr tablicę pięciu wartości typu T, zwracającej
największy element z tablicy. Wielkość tablicy jest ustalona, można ją na stałe zapisać w kodzie
pętli, bez przekazywania jako parametr. Przetestuj program przy użyciu funkcji z tablicą pięciu
wartości int i pięciu wartości double.

6. Napisz szablon funkcji maxn() pobierającej jako parametry tablicę typu T oraz liczbę elementów
tej tablicy, zwracającej największy element tablicy. Przetestuj w programie 5-elementową tablicę
wartości int i 4-elementową tablicę double. Program powinien korzystać ze specjalizacji przyjmującej
jako parametr tablicę typu char, zwracającej adres najdłuższego napisu. Jeśli jest kilka najdłuższych
łancuchów, funkcja powinna zwracać adres pierwszego z nich. Sprawdź specjalizację z tablicą
pięciu łańcuchów.

7. Zmodyfikuj listing 8.14 tak, aby stosował dwa szablony funkcji o nazwie SumArray(), zwracającej
sume elementów tablicy, a nie wypisującej zawartości tej tablicy. Program powinien podawać też
łączną liczbę przedmiotów i sumę zadłużenia.

