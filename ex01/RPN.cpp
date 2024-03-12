#include "RPN.hpp"

void	RPN::add()
{
	int	tmp1 = _stack.top();
	_stack.pop();
	int	tmp2 = _stack.top();
	_stack.pop();
	_stack.push(tmp1 + tmp2);
}

void	RPN::substraction()
{
	int	tmp1 = _stack.top();
	_stack.pop();
	int	tmp2 = _stack.top();
	_stack.pop();
	_stack.push(tmp2 - tmp1);	
}

void	RPN::multiple()
{
	int	tmp1 = _stack.top();
	_stack.pop();
	int	tmp2 = _stack.top();
	_stack.pop();
	_stack.push(tmp2 * tmp1);	
}

void	RPN::divide()
{
	int	tmp1 = _stack.top();
	_stack.pop();
	if (tmp1 == 0)
	{
		std::cout << "ERROR : Cannot divide by zero. " << std::endl;
		return ;
	}
	int	tmp2 = _stack.top();
	_stack.pop();
	_stack.push(tmp2 / tmp1);	
}

RPN::RPN(char *arg)
{
	int i = 0;

	while (arg[i] != '\0')
	{
		if (arg[i] <= '9' && arg[i] >= '0')
			_stack.push(static_cast<int>(arg[i] - 48));
		else if (arg[i] == ' ')
		{
			i++;
			continue;
		}
		else if (!isdigit(arg[i]) && _stack.size() >= 2)
		{
			if (arg[i] == '+')
				add();
			else if (arg[i] == '-')
				substraction();
			else if (arg[i] == '*')
				multiple();
			else if (arg[i] == '/')
				divide();
			else
			{
				std::cout << "ERROR : bad character : '" << arg[i] << "'" << std::endl;
				return ;
			}
		}
		i++;
	}
	std::cout << _stack.top() << std::endl;
}

void	RPN::printStack()
{
	std::stack<int> tmp = _stack;
	while (!tmp.empty())
	{
        std::cout << tmp.top() <<" ";
        tmp.pop();
	}
}

RPN::~RPN()
{
	std::cout << GREEN << "Fin du programme." << RESET << std::endl;
}

RPN::RPN()
{
	std::cout << GREEN << "Il se passe R." << RESET << std::endl;
}

RPN::RPN(const RPN &copie)
{
	std::stack<int> tmp;

	if (this != &copie)
	{
		while (tmp.size() != 0)
		{
			_stack.push(tmp.top());
			tmp.pop();
		}
	}
	std::cout << YELLOW << "RPN copié avec succès." << RESET << std::endl;
}

RPN& RPN::operator=(const RPN &copie)
{
	std::stack<int> tmp;
	tmp = copie._stack;

	if (!copie._stack.empty())
	{
		while (tmp.size() != 0)
		{
			_stack.push(tmp.top());
			tmp.pop();
		}
	}
	std::cout << BLUE << "RPN copié via opérateur avec succès." << RESET << std::endl;
	return (*this);
}

int len(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

const char *OPERATORS_ERROR::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Should Have For N Numbers N-1 Operators.";
	return (error);
}

const char *OPERATORS_BADEND::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Argument Should End With Operator.";
	return (error);
}

const char *ARGUMENT_BAD::what(void) const throw()
{
	const char *error = "\033[1;31mError\033[0m : Forbidden Or Unknown Char Detected.";
	return (error);
}