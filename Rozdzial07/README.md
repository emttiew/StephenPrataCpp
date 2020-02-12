# StephenPrataCpp Rozdział 07 - Polecenia: 

 
1. Napisz program, który poprosi użytkownika o podawanie dwóch liczb tak długo, aż jedna
będzie zerem. Dla każdej pary liczb program ma wyliczyć ich średnią harmoniczną. Funkcja ma
zwracać wynik funkcji main(), która z kolei wynik ten ma pokazać. Srednia harmoniczna liczb
to odwrotność średniej ich odwrotności; można ją wyliczyć następująco:

	średnia harmoniczna = 2.0-x-y/(x+y)


2. Napisz program proszący użytkownika o podanie do 10 wyników golfowych, które będą zapisane
w tablicy. Należy umożliwić zakończenie wprowadzania danych przed podaniem wszystkich
tych wyników. Program ma pokazać wyniki w jednym wierszu i podać wynik średni. Obsługa
wprowadzania danych, ich wyświetlania i obliczania średniej ma być zrealizowana w trzech
osobnych funkcjach przetwarzających tablice.


3. Oto deklaracja pewnej struktury: 
```
	struct pudlo
	{
	    char producent[40];
	    float wysokosc;
	    float szerokosc;
	    float dlugosc;
	    float objetosc;
	};
```
a) Napisz funkcję, której struktura pudlo zostanie przekazana przez wartość i która wyświetli
wartości wszystkich pól.

b) Napisz funkcję, której przekazany zostanie adres struktury pudlo i która ustawi wartość
pola objetosc na iloczyn trzech wymiarów.

c) Napisz prosty program używający powyższych dwóch funkcji.

4. Wiele loterii stanowych to odmiany prostej loterii opisanej na listingu 7.4. W odmianach tych
wybiera się kilka liczb z całego zbioru, nazywanego polem liczbowym. Można na przykład
wybrać 5 liczb z przedziału od 1 do 47. Wybiera się też z innego zbioru dodatkową liczbę,
nazywaną megaliczbą, power-ball itd.; ten zbiór może na przykład zawierać liczby od 1 do 27.
Aby wygrać nagrodę główną, trzeba odgadnąć wszystkie liczby. Prawdopodobieństwo wygranej
jest iloczynem prawdopodobieństwa odgadnięcia wszystkich liczb z pola i prawdopodobieństwa
odgadnięcia dodatkowej liczby. Na przykład prawdopodobieństwo wygrania w opisanym przykładzie
to prawdopodobieństwo prawidłowego wybrania 5 liczb z 47 razy prawdopodobieństwo
prawidłowego wybrania jednej liczby z 27. Zmodyfikuj listing 7.4 tak, aby mógł on obliczać
szanse wygranej na tego typu loteriach. 

5. Zdefiniuj funkcję rekurencyjną mającą parametr całkowitoliczbowy i zwracającą silnię tego
parametru. Przypomnijmy, że 3 silnia, zapisywane jako 3!, to 3-2!, i tak dalej, a 0! to z definicji 1.
Ogólnie, jeśli n jest większe od zera, n! = n(n-1)! Przetestuj funkcję w programie korzystającym
z pętli, w której użytkownik może zadawać różne liczby, dla których będzie liczona silnia.

6. Napisz program wykorzystujący następujące funkcje:
Funkcja fill_array() jako parametr pobiera nazwę tablicy liczb double oraz wiellkość tej tablicy.
Użytkownik jest proszony o podanie wartości double, które zostaną wpisane do tablicy. Pobieranie
danych jest przerywane, kiedy tablica jest pełna lub kiedy użytkownik poda daną niebędącą
liczbą. Funkcja zwraca liczbę rzeczywiście wprowadzonych wartości.
Funkcja show array() jako parametr pobiera nazwę tablicy liczb double oraz wielkość tej tablicy,
po czym pokazuje zawartość przekazanej tablicy.
Funkcja reverse_array() jako parametr pobiera nazwę tablicy liczb double oraz wielkość tej
tablicy, po czym odwraca kolejność liczb w przekazanej tablicy.
Program ma użyć opisanych funkcji do wypełnienia tablicy, wyświetlenia jej, odwrócenia
kolejności jej elementów i ponownego pokazania tablicy.

7. Zmodyfikuj program z listingu 7.7, zamieniając trzy funkcje obsługujące tablice tak, aby każda
z nich używała dwóch wskaźników określających zakres. Funkcja fill_array(), zamiast zwracać
aktualną liczbę elementów, ma zwrócić wskaźnik elementu znajdującego się za ostatnim wypełnionym
elementem. Inne funkcje mają używać tego wskaźnika jako drugiego parametru pozwalającego wykryć koniec danych.


10. Zaprojektuj funkcję calculate(), która pobierze dwie wartości typu double i wskaźnik funkcji
mającej dwa parametry double, zwracającej wartość double. Sama funkcja calculate() też ma
być typu double i ma zwracać wartość, którą wyliczy wskazywana funkcja po przekazaniu jej obu
parametrów calculate(). Załóżmy na przykład, że mamy następującą definicję funkcji add():
```
	double add(double x, double y)
	{
		return x + y:
	}
```
Wtedy wywołanie:
```
	double q = calculate(2.5, 10.4, add);
```
ma spowodować, że calculate() przekaże funkcji add() wartości 2,5 oraz 10,4, a następnie
zwróci wartość uzyskaną z add () (czyli w tym przypadku 12,9).

Użyj w programie opisanych funkcji oraz przynajmniej jednej funkcji dodatkowej podobnej
do add (). Program ma w pętli umożliwić użytkownikowi wprowadzanie par liczb, dla których
będzie wywoływana funkcja calculate() wywołująca add() i przynajmniej jedną funkcję
dodatkową. Osoby, które chcą wziąć się za bary z C++, mogą stworzyć tablicę wskaźników
funkcji podobnych do add () i w pętli stosować calculate() z tymi funkcjami. Podpowiedź:
deklaracja takiej tablicy z trzema wskaźnikami powinna wyglądać następująco:
```
	double (*pf[3]) (double, double);
```
Tablicę można zainicjalizować z wykorzystaniem normalnej składni inicjalizacji tablic,
podając nazwy funkcji jako adresy.

