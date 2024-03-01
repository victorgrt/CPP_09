#include "BitcoinExchange.hpp"

/*
Je creer une map remplie de la db. 
*/

Bitcoin::Bitcoin(char *file_name)
{

	setFileName(file_name);
	std::ifstream myfile(_file_name);
	if (isGood() == false)
	{
		std::cout << "Exit Safely.";
		exit(1);
	}
	std::string line;
	std::string date_to_find;
	std::string value_to_find;
	int i = 0;
	while (std::getline(myfile, line, '\n'))
	{
		int j = 0;
		date_to_find = "";
		value_to_find = "";
		try {
			checkLine(line, i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			exit(1);
		}

		while (line[j] == ' ' || line[j] == '\t')
			j++;
		while (line[j] != ' ' && line[j] != '\t')
		{
			date_to_find += line[j];
			j++;
		}
		if (date_to_find == "date")
		{
			i++;
			continue;
		}
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		j++;
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		while (line[j] != ' ' && line[j] != '\t' && line[j] != '\0')
		{
			value_to_find += line[j];
			j++;
		}
		std::cout << "trying to find '" << date_to_find << "'" << std::endl;
		try {
			std::cout << date_to_find << " : " << _data.at(date_to_find) * std::atof(value_to_find.c_str()) << BLUE << " (" <<  _data.at(date_to_find) << " * " << std::atof(value_to_find.c_str()) << ")" << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Need to go for the precedent one" << std::endl;
		}
		i++;
	}
}

void	Bitcoin::setMap()
{
	// std::map<std::string, float> _data;
	std::string buff_date;
	std::string buff_value;
	int j = 0;
	while (_raw[j] != '\n') //skip la premiere ligne
		j++;
	j++;
	for (unsigned int i = 0; i < _len_data; i++)
	{
		buff_date = "";
		buff_value = "";
		while (_raw[j] == ' ' || _raw[j] == '\t')
			j++;
		while (_raw[j] != ' ' && _raw[j] != '\t')
		{
			if (_raw[j] != '\n')
				buff_date += _raw[j];
			j++;
		}
		while ((_raw[j] == ' ' || _raw[j] == '\t') && _raw[j] != '\n')
			j++;
		j++;
		while ((_raw[j] == ' ' || _raw[j] == '\t') && _raw[j] != '\n')
			j++;
		while (_raw[j] != ' ' && _raw[j] != '\t' && _raw[j] != '\n')
		{
			if (_raw[j] != '\n')
				buff_value += _raw[j];
			j++;
		}
		while (_raw[j] != '\n')
			j++;
		_map[buff_date] = std::atof(buff_value.c_str());
	}
	if (_map.size() != _len_data)
		throw doubleData();
	std::map<std::string, float>::iterator it = _map.begin();
	std::map<std::string, float>::iterator ite = _map.end();
	while (it != ite)
	{
		std::cout << it->first << " = " << "'" << it->second << "'" << std::endl;
		++it;
	}
}

//Marche pas jsp pk
void	Bitcoin::printMap(std::map<std::string, float>map_to_print)
{
	std::map<std::string, float>::iterator it = map_to_print.begin();
	std::map<std::string, float>::iterator ite = map_to_print.end();
	while (it != ite)
	{
		std::cout << it->first << " = " << "'" << it->second << "'" << std::endl;
		++it;
	}
}

// void	Bitcoin::setMap()
// {
// 	std::map<std::string, float> _map;
// 	std::string buff_date;
// 	std::string buff_value;
// 	int j = 0;
	
// 	while (_raw[j] != '\n') //skip la premiere ligne
// 		j++;
// 	j++;
// 	for (unsigned int i = 0; i < _len_data; i++)
// 	{
// 		buff_date = "";
// 		buff_value = "";
// 		while (_raw[j] == ' ' || _raw[j] == '\t')
// 			j++;
// 		while (_raw[j] != ' ' && _raw[j] != '\t')
// 		{
// 			if (_raw[j] != '\n')
// 				buff_date += _raw[j];
// 			j++;
// 		}
// 		while ((_raw[j] == ' ' || _raw[j] == '\t') && _raw[j] != '\n')
// 			j++;
// 		j++;
// 		while ((_raw[j] == ' ' || _raw[j] == '\t') && _raw[j] != '\n')
// 			j++;
// 		while (_raw[j] != ' ' && _raw[j] != '\t' && _raw[j] != '\n')
// 		{
// 			if (_raw[j] != '\n')
// 				buff_value += _raw[j];
// 			j++;
// 		}
// 		while (_raw[j] != '\n')
// 			j++;
// 		_map[buff_date] = std::atof(buff_value.c_str());
// 	}
// 	if (_map.size() != _len_data)
// 		throw doubleData();
// 	std::map<std::string, float>::iterator it = _map.begin();
// 	std::map<std::string, float>::iterator ite = _map.end();
// 	while (it != ite)
// 	{
// 		std::cout << it->first << " = " << "'" << it->second << "'" << std::endl;
// 		++it;
// 	}
// }

void	Bitcoin::setFileName(const char *name)
{
	_file_name = name;
}

bool Bitcoin::isGood()
{
	std::ifstream myfile("data.csv");
	if (myfile.is_open() == false)
	{
		return (false);
	}
	std::string line;
	std::string buff_date;
	std::string buff_value;
	while (std::getline(myfile, line, '\n'))
	{
		int	i = 0;
		if (line.empty())
			break;
		buff_date = "";
		buff_value = "";
		if (line == "date,exchange_rate")
			continue;
		while (line[i] != ',' && line[i] != '\0')
		{
			buff_date += line[i];
			i++;
		}
		i++;
		while (line[i] != '\n' && line[i] != '\0')
		{
			buff_value += line[i];
			i++;
		}
		_data[buff_date] = std::atof(buff_value.c_str());
	}
	return (std::cout << "DataBase of size " << GREEN << _data.size() << RESET << " has been converted into a map." << std::endl, true);	 
}

// bool Bitcoin::isGood(const char *file)
// {
// 	std::ifstream myfile(file);
// 	if (myfile.is_open() == false)
// 	{
// 		std::cout << "Error opening file : '" << file << "' not found." << std::endl;
// 		return (false);
// 	}
// 	std::string line;
// 	std::string buff;
// 	int i = 0;
// 	while (std::getline(myfile, line, '\n'))
// 	{
// 		try
// 		{
// 			checkLine(line, i);
// 			buff = buff + line;
// 			buff += '\n';
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 			return (false);
// 		}
// 		i++;
// 	}
// 	_len_data = i - 1; //-1 pour le \n de fin
// 	_raw = buff;
// 	return true;	 
// }

bool	Bitcoin::checkLine(const std::string line, int index)
{
	int i = 0;
	std::string buff;
	if (line.empty())
		return (false);
	//check la first line pour trouver date, | et value
	if (index == 0) {
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		while (line[i] != ' ' && line[i] != '\t')
		{
			buff += line[i];
			i++;
		}
		if (buff != "date")
			throw Bitcoin::invalidFirstLine();
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != '|')
			throw Bitcoin::invalidFirstLine();
		buff = "";
		i++;
		if (line[i] == ' ' || line[i] == '\t') {
			while (line[i] == ' ' || line[i] == '\t')
				i++;
		}
		else
			throw Bitcoin::invalidFirstLine();
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		{
			buff += line[i];
			i++;
		}
		if (buff != "value")
			throw Bitcoin::invalidFirstLine();
		if (static_cast<size_t>(i) != line.length())
		{
			while (line[i] != '\0') {
				if (line[i] != ' ' && line[i] != '\t')
					throw Bitcoin::invalidFirstLine();
				i++;
			}
		}
	}
	// check le reste : trouver date, | et valeur
	else {
		std::string month_buff;
		std::string day_buff;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		while (line[i] != '\t' && line[i] != ' '){
			buff += line[i];
			i++;
		}
		if (buff.length() != 10 || (buff[4] != '-' && buff[7] != '-' ))
			throw Bitcoin::invalidFormat();
		month_buff += buff[5];
		month_buff += buff[6];
		day_buff += buff[8];
		day_buff += buff[9];
		if ((std::atoi(month_buff.c_str()) > 12 || std::atoi(month_buff.c_str()) == 0) || (std::atoi(day_buff.c_str()) == 0 || std::atoi(day_buff.c_str()) > 31))
				throw invalidData();
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (line[i] != '|')
				throw Bitcoin::invalidFormat();
		i++;
		std::string value_buff;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		while (line[i] != '\t' && line[i] != ' ' && line[i] != '\0')
		{
			value_buff += line[i];
			i++;
		}
		if (std::atof(value_buff.c_str()) < 0 || std::atof(value_buff.c_str()) > 1000)
			throw Bitcoin::invalidData();
		while (static_cast<size_t>(i) != line.length()){
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
				throw Bitcoin::invalidFormat();
			i++;
		}
	}
	return (true);
}

const char *Bitcoin::invalidValue::what() const throw()
{
	return (RED "Error thrown : Invalid Value Detected. (0-1000 needed)" RESET);
}

const char *Bitcoin::invalidData::what() const throw()
{
	return (RED "Error thrown : Invalid Data Detected." RESET);
}

const char *Bitcoin::invalidFormat::what() const throw()
{
	return (RED "Error thrown : Invalid Format Detected. ('YYYY-MM-DD | value' needed)" RESET);
}

const char *Bitcoin::invalidFirstLine::what() const throw()
{
	return (RED "Error thrown : Invalid First Line. ('date | value' needed)" RESET);
}

const char *Bitcoin::doubleData::what() const throw()
{
	return (RED "Error thrown : Double Data Detected. (1 value for 1 date needed)" RESET);
}