#include "Fixed.hpp"
#include "Point.hpp"
#include <string.h>
#include <iostream>

int main( void )
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);    
    Point outside(20.0f, 20.0f);
    Point onEdge(5.0f, 0.0f);   
    Point onVertex(0.0f, 0.0f); 

    std::cout << bsp(a, b, c, inside) << std::endl;
    std::cout << bsp(a, b, c, outside) << std::endl;
    std::cout << bsp(a, b, c, onEdge) << std::endl;
    std::cout << bsp(a, b, c, onVertex) << std::endl;
}