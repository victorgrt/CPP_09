#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iterator>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define UNDER "\033[4m"

class Bitcoin 
{
	private : 
		std::map<std::string, float> _map;
		std::map<std::string, float> _data;
		const char *_file_name;
		std::string _raw;
		std::string _raw_data;
		unsigned int _len_data;
	public : 
		Bitcoin();
		Bitcoin(char *file_name);
		Bitcoin(const Bitcoin &copie);
		Bitcoin &operator=(const Bitcoin &copie);
		~Bitcoin();

		bool checkLine(const std::string line, int index);
		bool isGood();

		void	setFileName(const char *name);

		class invalidValue : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
	
		class invalidFormat : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	
		class invalidFirstLine : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
	
		class invalidData : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
	
		class doubleData : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class negativeNumber : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class tooBigValue : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class valueNotFound : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};

		class emptyLine : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

#endif