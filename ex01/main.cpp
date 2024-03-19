#include "RPN.hpp"

bool	goodArgs(char *av)
{
	int	i = 0;
	int	operateurs = 0;
	int	operandes = 0;

	while (av[i] != '\0')
	{
		if (av[i] == '\0')
			break;
		if (av[i] == ' ')
		{
			i++;
			continue;
		}
		else if (av[i] <= '9' && av[i] >= '0' && av[i + 1] == ' ')
			operandes++;
		else if (av[i] == '+' || av[i] == '-' || av[i] == '*' || av[i] == '/')
			operateurs++;
		else if (av[i] != '+' && av[i] != '-' && av[i] != '/' && av[i] != '*' && (!(av[i] >= '0' && av[i] <= '9')))
			throw (ARGUMENT_BAD());
		else
			throw (OPERATORS_BADEND());
		i++;
	}
	i -= 1;
	if (av[i] != '+' && av[i] != '/' && av[i] != '*' && av[i] != '-')
		throw (OPERATORS_BADEND());
	if (operateurs != operandes - 1)
		throw (OPERATORS_ERROR());
	return (true);
}

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