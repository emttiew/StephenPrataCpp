#include <iostream>

template<typename T>
long double sum_values(const T& value)
{
    return static_cast<long double>(value);
}

template<typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{  
    return static_cast<long double>(value) + sum_values(args...);
}

int main()
{
    int a = 14;
    int b = 5;
    double c = 12.5;
    long double d = 124.98;

    std::cout << sum_values(a) << '\n';
    std::cout << sum_values(a, b) << '\n';
    std::cout << sum_values(a, b, c, d) << '\n';
    std::cout << sum_values(a, b, c, d, 'P') << '\n';
    return 0;
}