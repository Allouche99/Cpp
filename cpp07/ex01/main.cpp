#include <iostream>
#include "iter.hpp"

void print(const int &n)
{
    std::cout << n << std::endl;
}
void plusFortyTow(int &n)
{
    n = n + 42;
}
int main()
{
    int n = 4;
    int tab[4] = {42, 13, 37, 19};

    std::cout << "Test lecture :" << std::endl;
    iter(tab, n, print);

    std::cout << "Test modification :" << std::endl;
    iter(tab, n, plusFortyTow);
    iter(tab, n, print);

    return 0;
}