#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

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
	public :
		Merger();
		Merger(char **av, int ac);
		Merger(const Merger &copie);
		Merger &operator=(const Merger &copie);
		~Merger();

		void	printVictor();

		void FordJohnson();
};


class NOT_DIGIT : public std::exception {
	public:
		virtual const char *what() const throw();
};

class OVERFLOW : public std::exception {
	public:
		virtual const char *what() const throw();
};

#endif