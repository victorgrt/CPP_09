#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
// #include <ctime>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define UNDER "\033[4m"

class Merger{
	private :
		std::vector<int> _vectors;
		std::deque<int> _dq;
		int	_size;
	public :
		Merger();
		Merger(char **av, int ac);
		Merger(const Merger &copie);
		Merger &operator=(const Merger &copie);
		~Merger();


		void FordJohnson();

		void	swap(int i, int j);
		void	before();
		void	after();
		void	printTime(time_t start);

		int getMax(std::deque<int>paires, int i);
};

/*
template<typename Container>
void printContainer(const Container& c) {
    typename Container::const_iterator it = c.begin(); // Utilisation de typename pour indiquer qu'il s'agit d'un type dépendant
    typename Container::const_iterator ite = c.end(); // Utilisation de typename pour indiquer qu'il s'agit d'un type dépendant
    while (it != ite) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "\n";
}
*/

template<typename Container>
void printContainer(const Container &c) {
	typename Container::const_iterator it = c.begin();
	typename Container::const_iterator ite = c.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}

long long int getTime();


class NOT_DIGIT : public std::exception {
	public:
		virtual const char *what() const throw();
};

class OVERFLOW : public std::exception {
	public:
		virtual const char *what() const throw();
};

class MAX_ERROR : public std::exception {
	public:
		virtual const char *what() const throw();
};

#endif