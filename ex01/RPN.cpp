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
		std::cout << "ERROR DIVISION PAR 0 " << std::endl;
		return ;
	}
	int	tmp2 = _stack.top();
	_stack.pop();
	_stack.push(tmp2 / tmp1);	
}

RPN::RPN(char *arg){
	std::cout << arg << std::endl;
	_res = 0;
	int i = 0;
	std::stack<int> tmp;
	while (arg[i] != '\0')
	{
		if (arg[i] <= '9' && arg[i] >= '0')
		{
			_stack.push(static_cast<int>(arg[i] - 48));
		}
		else if (!isdigit(arg[i]) && _stack.size() >= 2)
		{
			//je prends les deux derniers et je les sorts et calcul
			if (arg[i] == '+')
				add();
			else if (arg[i] == '-')
				substraction();
			else if (arg[i] == '*')
				multiple();
			else if (arg[i] == '/')
				divide();
			else
				std::cout << "ERROR BAD CHAR" << std::endl;
		}
		i++;
	}
	tmp = _stack;
	while (!tmp.empty()) {
        std::cout << tmp.top() <<" ";
        tmp.pop();
    }
}

RPN::~RPN()
{

}
