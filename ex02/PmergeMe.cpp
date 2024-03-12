#include "PmergeMe.hpp"

/*DEFAULT CONSTRUCTOR*/
Merger::Merger()
{
	std::cout << GREEN << "Nothing Happens" << std::endl;
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
	std::cout << BLUE << "Before" << RESET << " : ";
	printVictor();
}


/* DESTRUCTEUR */
Merger::~Merger()
{
	std::cout << GREEN << "Merger detruit. Fin du programme." << RESET << std::endl;
}

/* FORD-JOHNSON ALGORITHM */
void	Merger::FordJohnson()
{
	std::cout << "All good to go" << std::endl;
}

/* UTILS */
void	Merger::printVictor()
{
	std::vector<int>::iterator it = _vectors.begin();
	std::vector<int>::iterator ite = _vectors.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}

/* ERRORS */
const char *NOT_DIGIT::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : All Arguments Need to Be Positiv Digit";
	return (error);
}

const char *OVERFLOW::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Int Overflow Detected.";
	return (error);
}