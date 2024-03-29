#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Bad usage : ./btc <file>\n", 0);
	std::string tmp = av[1];
	if (tmp.empty())
		return (std::cout << "File name must not be empty\n", 0);
	std::ifstream try_open(av[1]);
	if (try_open.is_open() == false)
		return (std::cout << "Error opening the file.", 0); 
	Bitcoin btc(av[1]);
	return (0);
}