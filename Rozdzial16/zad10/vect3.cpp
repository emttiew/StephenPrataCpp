// vect3.cpp -- użycie funkcji biblioteki STL
// większość kodu pochodzi z przykładu z książki
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
    std::string title;
    int rating;
    double price;
};

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool cheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2);
bool FillReview(std::shared_ptr<Review> & rr);
void ShowReview(const std::shared_ptr<Review> & rr);
int main()
{
    using namespace std;

    vector<shared_ptr<Review>> books;
    vector<shared_ptr<Review>> copy_books;
    shared_ptr<Review> temp;
    while (FillReview(temp))
        books.push_back(temp);
    copy_books = books;
    char choice;
    cout << "Dziękuję. Podałeś " << books.size() << " ocen książek:\n";
    cout << "Wybierz sposób sortowania: \nq = wyjście\n1 - kolejność wprowadzania\n2 - kolejność alfabetyczna\n"
            "3 - kolejność według ocen rosnąco\n4 - kolejność według ocen malejąco\n5 - kolejność według cen rosnąco\n"
            "6 - kolejność według cen malejąco\n";
    while(cin >> choice && choice != 'q')
        if (books.size() > 0)
        {
            switch (choice)
            {
            case '1':                
                cout << "Kolejność wporwadzania:\nOcena\tKsiążka\tCena\n";                 
                for_each(copy_books.begin(), copy_books.end(), ShowReview);
                cout << "Kolejny wybór: ";
                break;
            case '2':
                sort(books.begin(), books.end());
                cout << "Posortowane według tytułu:\nOcena\tKsiążka\tCena\n";
                for_each(books.begin(), books.end(), ShowReview);
                cout << "Kolejny wybór: ";
                break;
            case '3':
                sort(books.begin(), books.end(), worseThan);
                cout << "Posortowane według oceny rosnąco:\nOcena\tKsiążka\tCena\n";
                for_each(books.begin(), books.end(), ShowReview);
                cout << "Kolejny wybór: ";
                break;
            case '4':
                cout << "Posortowane według oceny malejąco:\nOcena\tKsiążka\tCena\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
                cout << "Kolejny wybór: ";
                break;
            case '5':
                sort(books.begin(), books.end(), cheaperThan);
                cout << "Posortowane według ceny rosnąco:\nOcena\tKsiążka\tCena\n";
                for_each(books.begin(), books.end(), ShowReview);
                cout << "Kolejny wybór: ";
                break;
            case '6':
                sort(books.begin(), books.end(), cheaperThan);
                cout << "Posortowane według ceny malejąco:\nOcena\tKsiążka\tCena\n";
                for_each(books.rbegin(), books.rend(), ShowReview);
                cout << "Kolejny wybór: ";
                break;
            default:
                cout << "Nie ma takiej opcji. Spróbuj ponownie: ";
                break;
            }      
        }
        else
            cout << "Brak danych. ";
    cout << "Koniec.\n";
    return 0;
}

bool operator<(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool cheaperThan(const std::shared_ptr<Review> & r1, const std::shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(std::shared_ptr<Review> & rr)
{
    std::shared_ptr<Review> temp(new Review);
    rr = temp;
    std::cout << "Wpisz tytuł książki (koniec, aby zakończyć): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "koniec")
        return false;
    std::cout << "Wpisz ocenę: ";
    std::cin >> rr->rating;
    std::cout << "Wpisz cenę: ";
    std::cin >> rr->price;
    if (!std::cin)
        return false;
    // pozbycie się reszty danych wejściowych
    while (std::cin.get() != '\n')
        continue;

    return true;
}

void ShowReview(const std::shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

