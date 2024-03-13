#pragma once

#include <iostream>
// #include <ctime>
#include <sys/time.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
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
		
		std::vector<int>_main;
		std::vector<int>_tmp;
		int	_size;
	public :
		Merger();
		Merger(char **av, int ac);
		Merger(const Merger &copie);
		Merger &operator=(const Merger &copie);
		~Merger();

		//main algo
		void FordJohnson(std::vector<int>&to_sort);
		void FordJohnson2();

		std::vector<int>getVector();
		void			setVector(std::vector<int>&to_set);

		int	getPivot(std::vector<int>&sequence, int low, int high);
		void	recursive_sort(std::vector<int>&sequence, int low, int high);
		void	binarySearch(std::vector<int>&main, int value);

		unsigned int _jackob(unsigned int n);
		//swap twho values
		// void	swap(std::vector<int>&vec, int i, int j);
		
		//printing utils
		void	before();
		void	after(std::vector<int>&toprint);
		void	printTime(time_t start);

		//get the max value for paires[i] and paires[i+1]
		int getMax(std::deque<int>paires, int i);
};

//get the current time in ms
long long int getTime();

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
