#include "BitcoinExchange.hpp"
#include <fstream>

bool	isGood(const char *file)
{
	std::ifstream myfile(file);
	if (myfile.is_open() == false)// ouvrable?
	{
		std::cout << "Error opening file : '" << file << "' not found." << std::endl;
		return (false);
	}
	std::string line;
	std::string buff;
	while (std::getline(myfile, line))
	{
		buff = buff + line + " sep ";
	}
	std::cout << buff << std::endl;
	if (line.empty())
		return (std::cout << "Error while reading file : '" << file << "' is empty" << std::endl, false);
	return true;
		 
}


//on met tout dans le constructeur par defaut ?
//container map looks good to use
//faudra un split pour mettre chaque ligne dans une partie du container
int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Bad usage : ./btc <file>\n", 0);
	std::string tmp = av[1];
	if (tmp.empty())
		return (std::cout << "File name must not be empty\n", 0);
	else if (isGood(av[1]) == false)
		return (std::cout << "Done" << std::endl, 0);
	// Bitcoin btc;
	return (0);
}