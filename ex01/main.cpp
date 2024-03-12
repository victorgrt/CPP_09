#include "RPN.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			return (std::cout << "Bad Usage.\n" << GREEN << "Try : ./RPN <\"argument\">" << RESET << std::endl, 0);
		if (goodArgs(av[1]) != true)
			return (0);
		RPN reverse(av[1]);
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}