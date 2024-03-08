#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define UNDER "\033[4m"

class RPN {
	private :
		std::stack<int> _stack;
		int	_operandes;
		int	_operateurs;
		int	_res;
	
	public :
		RPN();
		RPN(char *arg);
		~RPN();
		RPN(const RPN &copie);
		RPN &operator=(const RPN &copie);

		void	add();
		void	substraction();
		void	multiple();
};

#endif