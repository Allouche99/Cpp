#include <iostream>
#include "Array.hpp"

int main()
{
    Array<std::string> walo(10);
    std::cout << "walo size: " << walo.size() << std::endl;
    for(unsigned int i = 0; i < walo.size(); i++)
        std::cout << walo[i] << " ";
    std::cout<< std::endl;
    Array<int> a(3);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    std::cout << "Size: " << a.size() << std::endl;
    std::cout << "a[1]: " << a[1] << std::endl;

    Array<int> b(a);
    b[1] = 99;
    std::cout << "a[1]: " << a[1] << std::endl;
    std::cout << "b[1]: " << b[1] << std::endl;

    Array<int> c;
    c = a;
    c[0] = 77;
    std::cout << "a[0]: " << a[0] << std::endl;
    std::cout << "c[0]: " << c[0] << std::endl;
    try
    {
        std::cout << a[5] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    Array<std::string> strs(3);
    strs[0] = "hello"; strs[1] = "42"; strs[2] = "school";
     try
    {
        std::cout << strs[2] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}