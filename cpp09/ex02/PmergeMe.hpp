#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int argc, char **argv);

private:
    std::vector<int> _vector;
    std::deque<int>  _deque;
    double           _durationVector;
    double           _durationDeque;

    void parseArguments(int argc, char **argv);
    int  parseNumber(const char *str) const;
    void sortVector();
    void sortDeque();

    template <typename Container>
    void printContainer(const Container& c) const;
};

struct Pair
{
	int large;
	int small;
};


#endif