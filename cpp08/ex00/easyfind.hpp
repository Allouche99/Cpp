#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int nb)
{
    return (std::find(container.begin(), container.end(), nb));
}
#endif