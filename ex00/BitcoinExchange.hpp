#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <list>

class Bitcoin 
{
	private : 
		std::list<std::string> _list;
	public : 
		Bitcoin(std::string input);
};

#endif