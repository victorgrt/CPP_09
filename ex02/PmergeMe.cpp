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


/* DESTRUCTEUR */
Merger::~Merger()
{
	std::cout << GREEN << "Merger Class Detruite. Fin du programme." << RESET << std::endl;
}

/* FORD-JOHNSON ALGORITHM */
void	Merger::FordJohnson()
{
	if (_vectors.size() == 2)
	{
		if (_vectors.at(0) > _vectors.at(1))
			swap(0, 1);
		return;
	}

	//Regrouper les éléments en n/2 paires
	for (int i = 0; i < _size; i++)
	{
		_dq.push_back(_vectors[i]);
	}

	// Determiner le plus grand pour chaques paires.
	for (int i = 0; i < _size - 1; i+=2)
		getMax(_dq, i);

	//Trier recursivement les plus grands pour chaques paires
	// par ordre croissant pour avoir une Section? et
	// le mettre au debut de notre container.
	
	//Ca part en couilles.
}

/* UTILS */
void	Merger::swap(int i, int j)
{
	int	tmp;

	tmp = _vectors.at(i);
	_vectors.at(i) = _vectors.at(j);
	_vectors.at(j) = tmp; 
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


void	Merger::after()
{
	std::cout << MAGENTA << "After" << RESET << " : " << RESET;
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
	const char *error = "\033[1;31mError\033[0m : All Arguments Need to Be Positiv Digit";
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