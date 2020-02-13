# StephenPrataCpp Rozdział 09 - Polecenia:
1. Dany jest plik nagłówkowy:
```c++
//golf.h -- do pe9-1.cpp

const int Len = 40;
struct golf
{ 
  char fullanem[Len];
  int handicap;
};

//wersja nieinteraktywna
// funkcja ustawia w strukturze golf zadane nazwisko i handicap
// na podstawie argumentów wywoałania
void setgolf(golf & g, const char * name, int hc);

//wersja interaktywna:
// funkcja pobiera nazwisko i wartość handicapu od użytkowika
// i ustawia pola struktury g zgodnie z pobranymi wartościami;
// zwraca 1, jeśli udało się odczytać z wejścia wartość pola name,
// albo 0, kiedy pole name jest ciągiem pustym
void setgolf(golf & g);

//ustawia  handicap gracza
void handicap(golf & g, int hc);

//wyświetla zawartość pól struktury golf
void showgolf(const golf & g);
```
  Zauważ, że funkcja setgolf() została przeciążona. Zastosowanie jej pierwszej wersji wyglądałoby następująco:
```c++
golf ann;
setgolf(ann, "Ann Birdfree", 24);
```
  Wywołanie funkcji zawiera informacje umieszczane w polach struktury ann. W przypadku drugiej
  wersji funkcji setgolf() wyglądałoby to raczej tak jak poniżej:
```c++
golf andy;
setgolf(andy);
```
  Funkcja samodzielnie zapyta użytkownika programu o wartości dla pól struktury, odczyta je z wejścia
  i zapisze w polach struktury andy. Ta funkcja mogłaby (ale niekoniecznie) odwoływać się wewnętrznie
  do pierwszej wersji funkcji
  Złóż na bazie takiego nagłówka program wieloplikowy. Jeden z plików, o nazwie golf.cpp,
  powinien zawierać definicje odpowiadające prototypom z pliku nagłówkowego. Drugi plik
  powinien zawierać funkcję main () i demonstrować wszystkie możliwości zastosowania funkcji
  prototypowanych w pliku nagłówkowym. Możesz na przykład zastosować pętlę, w której
  użytkownik wprowadzałby dane dla tablicy struktur golf, przerywaną po wyczerpaniu tablicy
  bądź wprowadzeniu w roli nazwiska gracza ciągu pustego. Do obsługi struktury golf funkcja
  main() powinna stosować jedynie funkcje prototypowane w pliku nagłówkowym.
  
2. Przepisz kod z listingu 9.9, zastępując w nim tablicę znaków obiektem klasy string. Program 
  w nowej wersji nie powinien musieć sprawdzać, czy wprowadzany na wejście ciąg mieści się 
  w buforze, i wykrywać pusty wiersz poprzez porównanie obiektu bufora z literatem "".

3. Mając daną deklarację struktury:
```c++
struct chaff
{
  char dross[20];
  int slag;
};
```
  napisz program, który za pomocą miejscowej wersji operatora new przydzieli w buforze pamięć dla dwuelementowej tablicy
  takich struktur. Następnie program powinien przypisać wartości do składowych struktur (pamiętaj, że do kopiowania ciągów 
  znaków należy zastosować funkcję strcpy ()) iw prostej pętli wyświetlić ich wartości. W ramach wariantu pierwszego w roli
  bufora można wykorzystać tablicę statyczną, jak na listingu 9.10. Drugi wariant powinien przydzielać
  bufor wywołaniem zwykłego operatora new.
  
 4. Napisz trzyplikowy program bazujący na poniższej przestrzeni nazw:
 ```c++
namespace SALES
{
  const int QUARTERS = 4;
  struct Sales
{
  double sales [QUARTERS];
  double average;
  double max;
  double min;
};
// kopiuje tablięc ar
// do składowej sales struktury s i oblicza oraz zachowuje w odpowiednich
// składowych struktury sales wartości: średnią, minimalną i maksymalną
// zeruje pozostałe elementy tablicy sales (jeśli są)
void setSales (Sales & s, const double ar[], int n);

// pobiera interaktywnie informacje dla 4 kwartałów
// zachowuje je w składowej sales struktury s i oblicza oraz zachowuje
// w odpowiednich składowych s wartość średnią, minimalną i maksymalną
void setSales (Sales & s);

// wyświetla komplet informacji ze struktury s
void showSales (const Sales & s);
```
Pierwszy z plików powinien być plikiem nagłówkowym deklarującym powyższą przestrzeń nazw.
Drugi plik powinien zawierać kod źródłowy uzupełniający przestrzeń nazw z pliku nagłówkowego
o definicje zadeklarowanych w niej funkcji. Wreszcie trzeci plik powinien deklarować dwa
obiekty typu Sales. Jeden z nich powinien wypełnić interaktywną wersję funkcji setSales(),
drugi jej wersję nieinteraktywną. Na koniec powinien wyświetlić zawartość obu struktur
wywołaniem showSales().
