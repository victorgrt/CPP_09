#include "PmergeMe.hpp"

long long int getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

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
	long long int starting_time = getTime();

	if (ac <= 1)
		return (std::cout << RED << "Error\n" << RESET << "Bad Usage : './PmergeMe <numbers...>' needed." << std::endl, 0);

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

	try
	{
		//Initialisation
		Merger PmergeMe(av, ac);
		if (ac == 2)
		{
			std::vector<int>empty;
			PmergeMe.before();
			PmergeMe.after(empty);
			PmergeMe.printTime(starting_time);
			return (0);
		}
		// std::vector<int>empty;
		//Print du before
		PmergeMe.before();
		std::vector<int>tmp = PmergeMe.getVector();
		PmergeMe.FordJohnson(tmp);
		// PmergeMe.FordJohnson2();
		PmergeMe.after(tmp);
		PmergeMe.printTime(starting_time);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
	return (0);
}