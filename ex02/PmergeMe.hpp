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
		long long int _starting_time;
		int	_size;
		
	public :
		Merger();
		Merger(char **av, int ac);
		Merger(const Merger &copie);
		Merger &operator=(const Merger &copie);
		~Merger();

		//main algo
		template<typename Container>
		void	binarySearch(Container &search, int value){
			int low = 0;
			int high = search.size() - 1;
			
			while (low <= high)
			{
				int mid = low + (high - low) / 2;
				if (search[mid] == value)
					return ;
			else if (search[mid] < value)
				low = mid + 1;
			else
				high = mid - 1;
			}
			search.insert(search.begin() + low, value);
		}

		template<typename Container>
		void	fordJohnson(Container &to_sort){
		{
			std::cout << MAGENTA << "USING CONTAINERS LIKE A BOSS" << RESET << std::endl;

			Container main;
			Container tmp;

			//sorting our pairs 2 by 2
			for (size_t i = 0; i < to_sort.size() - 1; i += 2)
			{
				if (to_sort[i] > to_sort[i + 1])
				{
					std::swap(to_sort[i], to_sort[i+1]);
				}
			}
			//in case there is more than two
			//elements
			if (to_sort.size() > 2)
			{
				//we add value in main and the next
				//one in tmp
				for (size_t i = 0; i < to_sort.size(); i += 2)
				{
					main.push_back(to_sort[i]);
					if (i < to_sort.size() - 1)
						tmp.push_back(to_sort[i + 1]);
				}
				//we sort the main container
				fordJohnson(main);
				size_t psize = tmp.size();
				for (size_t i = 0; i < psize; i++)
				{
					size_t j = 0;
					size_t sortIndex = 0;
					for (; _jackob(j) < i; j++){}
					if (j)
					{
						if (_jackob(j) >= psize - 1)
							sortIndex = psize - (i - _jackob(j - 1));
						else
							sortIndex = _jackob(j) + 1 - (i - _jackob(j - 1));
					}
					binarySearch(main, tmp[sortIndex]);
				}
				to_sort = main;
			}
		}
		}

		//void	FordJohnson(std::vector<int>&to_sort);
		//void	binarySearch(std::vector<int>&main, int value);
		unsigned int _jackob(unsigned int n);
		
		//printing utils
		void	before();
		void	after();
		void	printTime(time_t start);

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

#endif
