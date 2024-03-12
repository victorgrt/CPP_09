#include "PmergeMe.hpp"


bool isFullDigit(int ac, char **av)
{
	int i = 1;
	while (i < ac)
	{
		std::string tmp = av[i];
		for (size_t j = 0; j < tmp.length(); j++)
			if (isdigit(tmp[j]) == 0)
			{
				throw NOT_DIGIT();
				return (false);
			}
		i++;
	}
	return (true);
}


int	main(int ac, char **av)
{
	std::time_t starting_time;
	std::time_t ending_time;

	if (ac <= 1)
		return (std::cout << RED << "Error\n" << RESET << "Bad Usage : './PmergeMe <numbers...>' needed." << std::endl, 0);
	starting_time = std::time(NULL);
	//We check that all our agruments are full of digits.
	try
	{
		if (isFullDigit(ac, av) != true)
			return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	//We put our arguments into
	// vectors inside our class.
	//We print the arg and "Before :"
	try
	{
		//Initialisation de la classe,
		//du vecteur et de la size.
		Merger PmergeMe(av, ac);
		
		//Sorting with Ford-Johnson
		PmergeMe.FordJohnson();
	
		//Printing the "After :" with 
		//sorted args.
		std::cout << MAGENTA << "After" << RESET << " : " << RESET;
		PmergeMe.printVictor();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}


	//Get the time it took and print it.
	ending_time = std::time(NULL);
	std::cout << "Temps d'execution : " << BLUE << (ending_time - starting_time) * 1000 << "ms" << RESET << std::endl;
	return (0);
}