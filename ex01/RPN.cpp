#include "RPN.hpp"

RPN::RPN(char *arg){
	std::cout << arg << std::endl;

	int i = 0;
	int res = 0;
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
			{
				res += _stack.top();
				_stack.pop();
				std::cout << res << " + ";
				res += _stack.top();
				std::cout << _stack.top() << " = " << res << std::endl;
				_stack.pop();
			}
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
