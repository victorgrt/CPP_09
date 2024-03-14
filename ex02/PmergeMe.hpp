#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
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
		std::deque<int> _queue;
		long long int _starting_time;
		long long int _2ndstarting_time;	
		int	_size;
		
	public :
		Merger();
		Merger(char **av, int ac);
		Merger(const Merger &copie);
		Merger &operator=(const Merger &copie);
		~Merger();

		//main algo
		template<typename Container>
		void	binarySearch(Container &search, int value);

		template<typename Container>
		void	fordJohnson(Container &to_sort); 

		unsigned int _jackob(unsigned int n);
		
		//printing utils
		void	before();
		
		template<typename Container>	
		void	after(Container& container);
		void	printTime(time_t start, int type);

};

//get the current time in ms
long long int getTime();

template<typename Container>
void printContainer(const Container &c);

class NOT_DIGIT : public std::exception {
	public:
		virtual const char *what() const throw();
};

class OVERFLOW : public std::exception {
	public:
		virtual const char *what() const throw();
};

#endif