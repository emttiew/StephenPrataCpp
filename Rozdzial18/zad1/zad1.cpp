#include <initializer_list>
#include <iostream>

template<typename T>
T average_list(std::initializer_list<T> list);

int main()
{
    using namespace std;
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
    cout << average_list({20, 30, 19, 17, 4, 38}) << endl;
    auto ad = average_list<double>({'A', 70, 65.33});
    cout << ad << endl;
    return 0;
}


template<typename T>
T average_list(std::initializer_list<T> list)
{
    T sum;
    for(auto & x : list )
        sum += x;
    return sum / list.size();
}