#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> Lotto(int no_fields, int selected);

int main()
{
    int no_fields, selected;
    std::cout << "Podaj liczbę pól Lotto:\n";
    std::cin >> no_fields;
    std::cout << "Podaj ilość wybranych liczb:\n";
    std::cin >> selected;

    std::vector<int> winner;
    winner = Lotto(no_fields, selected);
    std::cout << "Wylosowane liczby to: \n";
    for(auto v : winner)
        std::cout << v << '\n';

    return 0;
}

std::vector<int> Lotto(int no_fields, int selected)
{
    if(no_fields < selected)
    {
        std::cout << "Ilość wybranych numerów nie może przekraczać ilości pól.\n";
        exit(EXIT_FAILURE);
    }
    if(no_fields < 0 || select < 0)
    {
        std::cout << "Oba pola muszą być większe od 0.\n";
    }
    std::vector<int> all_numbers;
    std::vector<int> win_numbers;
    for(int i = 1; i < no_fields + 1; i++)
    {
        all_numbers.push_back(i);
    }
    std::random_shuffle(all_numbers.begin(), all_numbers.end());
    for(int i = 0; i < selected; i++)
    {
        win_numbers.push_back(all_numbers[i]);
    }

    return win_numbers;
}