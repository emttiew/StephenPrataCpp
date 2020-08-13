#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <iostream>

int main()
{
    const int test_size = 10000000;
    std::vector<int> vi0(test_size);
    std::generate(vi0.begin(), vi0.end(), []() {
        return rand() % 1000;
    });

    std::vector<int> vi(test_size);
    std::list<int> li(test_size);

    vi = vi0;
    li.insert(li.begin(), vi0.begin(), vi0.end());

    /*
    * sort block time measurement
    */
    {
        clock_t start = clock();
        std::sort(vi.begin(), vi.end());
        clock_t end = clock();
        std::cout << "Czas wykonywania operacji sortowania vectora\n za pomocą STL-owego alogrytmu sort(): " << (double)(end - start)/CLOCKS_PER_SEC << '\n';
    }
    {
        clock_t start = clock();
        li.sort();
        clock_t end = clock();
        std::cout << "Czas wykonywania operacji sortowania listy\n metodą sort() klasy list: " << (double)(end - start)/CLOCKS_PER_SEC << '\n';
    }

    /*
    * copy and sort block time measurement
    */
    li.assign(vi0.begin(), vi0.end());
    std::vector<int> vi2(test_size);
    {
        clock_t start = clock();
        std::copy(li.begin(), li.end(), std::back_inserter(vi2));
        std::sort(vi2.begin(), vi2.end());
        li.assign(vi2.begin(), vi2.end());
        clock_t end = clock();
        std::cout << "Czas wykonywania operacji kopiowania listy do vectora (i z powrotem)\n"
                        "korzytając z algorytmu STL copy() oraz sortowania vectora: " << (double)(end - start)/CLOCKS_PER_SEC << '\n';
    }

        
    return 0;
}