#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream> // for std::runtime_error
#include <fstream> // for std::ifstream
#include <cstring>
#include <sstream>
#include <regex.h>
#include <stdlib.h>
#include <map>
#include <iomanip>

typedef enum {
	INPUT,
	DATA
} e_type;

class Date{
	private:
		unsigned int year;
		unsigned int month;
		unsigned int day;
	public:
		Date(){};
		Date(std::string year, std::string month, std::string day);
		~Date(){};
		unsigned int getYear() const;
		unsigned int getMonth() const;
		unsigned int getDay() const;
		void setYear(unsigned int year);
		void setMonth(unsigned int month);
		void setDay(unsigned int day);
		bool operator==(const Date &date) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		friend std::ostream &operator<<(std::ostream& os, const Date& date);
};

class BitcoinExchange {
	private:
		std::map<Date, double> bitcoinExchange;
	public:
		BitcoinExchange(): bitcoinExchange(){};
		BitcoinExchange(Date &date, double &price, e_type type);
		~BitcoinExchange(){};
		Date const &getDate(Date date, std::map<Date, double> const &data) const;
		double const &getValue(Date &date) const;
		void	setMap(Date &date, double &price, e_type type);
		std::map<Date, double> const &getMap()	const;
};

#endif
