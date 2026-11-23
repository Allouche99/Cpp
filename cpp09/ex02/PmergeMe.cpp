#include "PmergeMe.hpp"

#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

// C  : conteneur d'entiers (std::vector<int> ou std::deque<int>)
// PC : conteneur de paires (std::vector<Pair> ou std::deque<Pair>)
template <typename C, typename PC>
static C fordJohnson(const C& seq)
{
	size_t n = seq.size();
	if (n <= 1)
		return seq;

	// ---- 1. Former les paires (1 comparaison par paire) ----
	bool hasStraggler = (n % 2 != 0);
	int  straggler = hasStraggler ? seq[n - 1] : 0;

	PC pairs;
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		Pair p;
		if (seq[i] > seq[i + 1])
		{
			p.large = seq[i];
			p.small = seq[i + 1];
		}
		else
		{
			p.large = seq[i + 1];
			p.small = seq[i];
		}
		pairs.push_back(p);
	}

	// ---- 2. Trier récursivement les "large" ----
	C larges;
	for (size_t i = 0; i < pairs.size(); i++)
		larges.push_back(pairs[i].large);
	larges = fordJohnson<C, PC>(larges);

	// Remettre les paires dans l'ordre des larges triés
	// (le tableau "used" gère correctement les doublons)
	PC sorted;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < larges.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].large == larges[i])
			{
				sorted.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	// ---- 3. Main chain : b1, a1, a2, ..., ak ----
	C mainChain;
	mainChain.push_back(sorted[0].small);
	for (size_t i = 0; i < sorted.size(); i++)
		mainChain.push_back(sorted[i].large);

	// ---- 4. Insérer b2..bk dans l'ordre de k ----
	size_t k = sorted.size();
	size_t prevJ = 1;
	size_t jLarge = 1;
	size_t jSmale = 1;
	while (prevJ < k)
	{
		size_t jc = jSmale + 2 * jLarge; // 3, 5, 11, 21, 43...
		jLarge = jSmale;
		jSmale = jc;
		size_t cur = (jc < k) ? jc : k;

		for (size_t idx = cur; idx > prevJ; idx--)
		{
			int small = sorted[idx - 1].small;
			int large = sorted[idx - 1].large;

			// On cherche b uniquement avant a (b < a)
			typename C::iterator bound =
				std::find(mainChain.begin(), mainChain.end(), large);
			typename C::iterator pos =
				std::lower_bound(mainChain.begin(), bound, small);
			mainChain.insert(pos, small);
		}
		prevJ = cur;
	}

	if (hasStraggler)
	{
		typename C::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	return mainChain;
}

PmergeMe::PmergeMe() : _durationVector(0), _durationDeque(0) {}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vector(other._vector),
	  _deque(other._deque),
	  _durationVector(other._durationVector),
	  _durationDeque(other._durationDeque)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
		_durationVector = other._durationVector;
		_durationDeque = other._durationDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}


int PmergeMe::parseNumber(const char *str) const
{
	char *end;

	errno = 0;
	long value = std::strtol(str, &end, 10);

	if (str[0] == '\0' || end == str || *end != '\0')
		throw std::runtime_error("Error: invalid argument");
	if (errno == ERANGE || value > INT_MAX)
		throw std::runtime_error("Error: number exceeds INT_MAX");
	if (value <= 0)
		throw std::runtime_error("Error: numbers must be positive");

	return static_cast<int>(value);
}

void PmergeMe::parseArguments(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error: no arguments provided");

	for (int i = 1; i < argc; i++)
	{
		int n = parseNumber(argv[i]);
		_vector.push_back(n);
		_deque.push_back(n);
	}
}

template <typename Container>
void PmergeMe::printContainer(const Container& c) const
{
	for (size_t i = 0; i < c.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << c[i];
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector()
{
	clock_t start = clock();
	_vector = fordJohnson<std::vector<int>, std::vector<Pair> >(_vector);
	clock_t end = clock();
	_durationVector = static_cast<double>(end - start)  * 1000000 / CLOCKS_PER_SEC;
}

void PmergeMe::sortDeque()
{
	clock_t start = clock();

	_deque = fordJohnson<std::deque<int>, std::deque<Pair> >(_deque);

	clock_t end = clock();
	_durationDeque = static_cast<double>(end - start) * 1000000  / CLOCKS_PER_SEC;
}

void PmergeMe::run(int argc, char **argv)
{
	parseArguments(argc, argv);

	std::cout << "Before: ";
	printContainer(_vector);

	sortVector();
	sortDeque();

	std::cout << "After:  ";
	printContainer(_vector);

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : "
			  << _durationVector<< " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : "
			  << _durationDeque<< " us" << std::endl;
}