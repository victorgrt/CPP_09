#include "RPN.hpp"

//aller jusqua operateur et je sort les deux derniers et j'opere

/*
Check digit entre 0 et 9
Check que des digits et operateurs
Check fini par minimum un operateur
Check pour N digits N-1 operateurs
*/
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
		else
			return (false);
		i++;
	}
	std::cout << "operandes : " << operandes << std::endl;
	std::cout << "operateurs : " << operateurs << std::endl;
	i -= 1;
	if (av[i] != '+' && av[i] != '/' && av[i] != '*' && av[i] != '-')
		return (false);
	if (operateurs != operandes - 1)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	std::stack<int> ma_stack;
	if (ac != 2)
		return (std::cout << "Bad Usage." << std::endl, 0);
	if (goodArgs(av[1]) == false)
		return (std::cout << "Bad Arguments." << std::endl, 0);
	RPN reverse(av[1]);
	return (0);
}