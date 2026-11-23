#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> nbVector;
	nbVector.push_back(10);
	nbVector.push_back(20);
	nbVector.push_back(30);

	std::vector<int>::iterator it = easyfind(nbVector, 30);
	if (it == nbVector.end())
		std::cout << "not Found" << std::endl;
	else
		std::cout << "Found: " << *it << std::endl;

	std::list<int> nbList;
	nbList.push_back(10);
	nbList.push_back(20);
	nbList.push_back(30);

	std::list<int>::iterator itList = easyfind(nbList, 0);
	if (itList == nbList.end())
		std::cout << "not Found" << std::endl;
	else
		std::cout << "Found: " << *itList<< std::endl;

	std::vector<int> nbnvec1;
	nbnvec1.push_back(-1);
	nbnvec1.push_back(-20);
	nbnvec1.push_back(-30);

	it = easyfind(nbnvec1,-20);
	if (it == nbnvec1.end())
		std::cout << "not Found" << std::endl;
	else
		std::cout << "Found: " << *it << std::endl;
   
	return 0;
}