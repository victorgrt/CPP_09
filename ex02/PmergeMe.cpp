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
	_size = _vectors.size();
	std::cout << "Size : " << _size << std::endl;
}


/* DESTRUCTEUR */
Merger::~Merger()
{
	std::cout << GREEN << "Merger detruit. Fin du programme." << RESET << std::endl;
}

/* FORD-JOHNSON ALGORITHM */
void	Merger::FordJohnson()
{
	//Regrouper les éléments en n/2 paires
	std::deque<int> paires;
	for (int i = 0; i < _size; i++)
	{
		if (_size % 2 == 0)
		{
			paires.push_front(_vectors[i]);
			i++;
			paires.push_back(_vectors[i]);
		}
	}
	// paires.push_front(_vectors[0]);
	// paires.push_back(_vectors[1]);


	std::deque<int>::iterator it = paires.begin();
	std::deque<int>::iterator ite = paires.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Determiner le plus grand pour chaques paires.
	getMax(paires);

	//Crier recursivement les plus grands pour chaques paires
	// par ordre croissant pour avoir une Section? et
	// le mettre au debut de notre container.
	
	//Ca part en couilles.
}

/* UTILS */
void	Merger::getMax(std::deque<int>paires)
{
	std::cout << "Max : ";
	if (paires.front() > paires.back())
		std::cout << paires.front() << std::endl;
	else
		std::cout << paires.back() << std::endl;
}

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