#include "PmergeMe.hpp"

/*CANONICAL FORM*/
Merger::Merger()
{
	std::cout << GREEN << "Nothing Happens Noob" << std::endl;
}
	
Merger::Merger(const Merger &copie)
{
	(void) copie;
}

Merger& Merger::operator=(const Merger &copie)
{
	(void) copie;
	return *this;
}

Merger::~Merger()
{
	std::cout << GREEN << "Merger Class Detruite. Fin du programme." << RESET << std::endl;
}

//=========================================================//
/* NORMAL BEHAVIOR */
Merger::Merger(char **av, int ac)
{
	_starting_time = getTime();
	for (int i = 1; i < ac; i++)
	{
		long tmp = std::atol(av[i]);
		if (tmp > 2147483647)
			throw (OVERFLOW());
		else if (checkDoublon(tmp) == false)
			throw (DOUBLON());
		_vectors.push_back(tmp);
		_queue.push_back(tmp);
	}
	_size = _vectors.size();
	before();
	fordJohnson(_vectors);
	after(_vectors);
	printTime(_starting_time, 0);

	//SAME THING FOR SECOND CONTAINER
	_2ndstarting_time = getTime();
	for (int i = 1; i < ac; i++)
	{
		long tmp = std::atol(av[i]);
		if (tmp > 2147483647)
			throw (OVERFLOW());
		_queue.push_back(tmp);
	}
	fordJohnson(_queue);
	printTime(_2ndstarting_time, 1);
}

//=========================================================//
/* FORD-JOHNSON UTILS */
bool	Merger::checkDoublon(int to_check)
{
	std::vector<int>::iterator it = _vectors.begin();
	std::vector<int>::iterator ite = _vectors.end();

	while (it != ite)
	{
		if (to_check == *it)
			return (false);
		++it;
	}
	return (true);
}

template<typename Container>
void	Merger::fordJohnson(Container &to_sort)
{
	Container main;
	Container tmp;
	//sorting our pairs two by two till the end
	//45 0 226 79 5 9
	for (size_t i = 0; i < to_sort.size() - 1; i += 2)
	{
		if (to_sort[i] > to_sort[i + 1])
		{
			std::swap(to_sort[i], to_sort[i+1]);
		}
	}
	//0 45 79 226 5 9 
	//in case there is more than two
	//elements
	if (to_sort.size() > 2)
	{
		//we add even in main and odd in tmp
		for (size_t i = 0; i < to_sort.size(); i += 2)
		{
			main.push_back(to_sort[i]);
			if (i < to_sort.size() - 1)
				tmp.push_back(to_sort[i + 1]);
		}
		//0 45 79 226 5 9 
		//main : 0 79 5
		//tmp : 45 226 9
		//we sort the main container with recursive
		fordJohnson(main);
		//to_sort general = 0 79
		//main : 0 79
		//tmp = 45 226 9 5
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

template <typename Container>
void	Merger::binarySearch(Container &search, int value)
{
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


unsigned int Merger::_jackob(unsigned int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (_jackob(n - 1) + 2 * _jackob(n - 2));
}

//=========================================================//
/*PRINTER*/
template<typename Container>
void	Merger::after(Container &container)
{
	std::cout << MAGENTA << "After" << RESET << " : " << RESET;
	printContainer(container);
}

void	Merger::before()
{
	std::cout << BLUE << "Before" << RESET << " : ";
	printContainer(_vectors);
}

void	Merger::printTime(time_t start, int type)
{
	long long int ending_time = getTime(); 
	if (type == 0)
		std::cout << "Temps d'execution avec std::vector : " << BLUE << (ending_time - start) << "ms" << RESET << std::endl;
	else
		std::cout << "Temps d'execution avec std::deque : " << BLUE << (ending_time - start) << "ms" << RESET << std::endl;
}

template<typename Container>
void printContainer(const Container &c)
{
	typename Container::const_iterator it = c.begin();
	typename Container::const_iterator ite = c.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}

//=========================================================//
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

const char *DOUBLON::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Doublon Detected.";
	return (error);
}
