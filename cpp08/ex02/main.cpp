#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()

{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout <<"size: "<<  mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "Reverse iteration:" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::stack<int> s(mstack);

    std::cout << "same test whith list:"<< std::endl;

    std::list<int> ls;
    ls.push_back(5);
    ls.push_back(17);
    std::cout << ls.back() << std::endl;
    ls.pop_back();
    std::cout << ls.size() << std::endl;
    ls.push_back(3);
    ls.push_back(5);
    ls.push_back(737);
    ls.push_back(0);
    std::list<int>::iterator itLs = ls.begin();
    std::list<int>::iterator iteLs = ls.end();
    ++itLs;
    --itLs;
    while (itLs != iteLs)
    {
        std::cout << *itLs << std::endl;
        ++itLs;
    }
    return 0;
}