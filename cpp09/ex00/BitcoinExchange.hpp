#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <fstream>
#include <string>
#include <iostream>
# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
        
        static std::string	trim(const std::string& str);
		static bool			isValidDate(const std::string& date);
		static bool			isValidValue(const std::string& str, double& value);
		double				getRate(const std::string& date) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	loadData(const std::string& filename);
		void	processInput(const std::string& filename) const;
};

#endif