#include "PmergeMe.hpp"
/*DEFAULT CONSTRUCTOR*/
Merger::Merger()
{
	std::cout << GREEN << "Nothing Happens Noob" << std::endl;
}

/* NORMAL BEHAVIOR */
Merger::Merger(char **av, int ac)
{
	for (int i = 1; i < ac; i++)
	{
		long tmp = std::atol(av[i]);
		if (tmp > 2147483647)
			throw (OVERFLOW());
		_vectors.push_back(tmp);
	}
	_size = _vectors.size();
}

std::vector<int> Merger::getVector()
{
	return (_vectors);
}

/* DESTRUCTEUR */
Merger::~Merger()
{
	std::cout << GREEN << "Merger Class Detruite. Fin du programme." << RESET << std::endl;
}

void	Merger::FordJohnson2()
{
	std::vector<int>main;
	std::vector<int>tmp;

	for (size_t i = 0; i < _vectors.size() - 1; i += 2)
	{
		if (_vectors[i] > _vectors[i + 1])
		{
			std::swap(_vectors[i], _vectors[i+1]);
		}
	}
	if (_vectors.size() > 2)
	{
		for (size_t i = 0; i < _vectors.size(); i += 2)
		{
			main.push_back(_vectors[i]);
			if (i < _vectors.size() - 1)
				tmp.push_back(_vectors[i + 1]);
		}
		FordJohnson(main);
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
		_vectors = main;
	}	
}

/* FORD-JOHNSON ALGORITHM */
void	Merger::FordJohnson(std::vector<int>&to_sort)
{
	std::vector<int>main;
	std::vector<int>tmp;

	for (size_t i = 0; i < to_sort.size() - 1; i += 2)
	{
		if (to_sort[i] > to_sort[i + 1])
		{
			std::swap(to_sort[i], to_sort[i+1]);
		}
	}
	if (to_sort.size() > 2)
	{
		for (size_t i = 0; i < to_sort.size(); i += 2)
		{
			main.push_back(to_sort[i]);
			if (i < to_sort.size() - 1)
				tmp.push_back(to_sort[i + 1]);
		}
		FordJohnson(main);
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

void	Merger::binarySearch(std::vector<int>&main, int value)
{
	int	low = 0;
	int high = main.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (main[mid] == value)
		{
			return;
		}
		else if (main[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	main.insert(main.begin() + low, value);
}

unsigned int Merger::_jackob(unsigned int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (_jackob(n - 1) + 2 * _jackob(n - 2));
}

int	Merger::getMax(std::deque<int>paires, int i)
{
	if (_size % 2 == 0 && i < _size - 1)
	{
		std::cout << "Max between " << paires.at(i) << " and " << paires.at(i + 1) << " : ";
		if (paires.at(i) < paires.at(i + 1))
		{
			std::cout << paires.at(i + 1) << std::endl;
			return (paires.at(i + 1));
		}
		else
		{
			std::cout << paires.at(i) << std::endl;
			return (paires.at(i));
		}
	}
	else if (_size % 2 != 0 && i < _size - 2)
	{
		std::cout << "Max between " << paires.at(i) << " and " << paires.at(i + 1) << " : ";
		if (paires.at(i) < paires.at(i + 1))
		{
			std::cout << paires.at(i + 1) << std::endl;
			return (paires.at(i + 1));
		}
		else
		{
			std::cout << paires.at(i) << std::endl;
			return (paires.at(i));
		}
		
	}
	throw (MAX_ERROR());
}

/*PRINTER*/
void	Merger::after(std::vector<int>&to_print)
{
	std::cout << MAGENTA << "After" << RESET << " : " << RESET;
	if (!to_print.empty())
		printContainer(to_print);
	else 
		printContainer(_vectors);
}

void	Merger::before()
{
	std::cout << BLUE << "Before" << RESET << " : ";
	printContainer(_vectors);
}

void	Merger::printTime(time_t start)
{
	long long int ending_time = getTime(); 
	std::cout << "Temps d'execution : " << BLUE << (ending_time - start) << "ms" << RESET << std::endl;
}

/* EXCEPTIONS */
const char *NOT_DIGIT::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : All Arguments Need to Be Positive Digit";
	return (error);
}

const char *OVERFLOW::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Int Overflow Detected.";
	return (error);
}

const char *MAX_ERROR::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Int Max Couldn't Be Found.";
	return (error);
}