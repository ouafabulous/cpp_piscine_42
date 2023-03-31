#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream> // for std::runtime_error
#include <fstream> // for std::ifstream
#include <cstring>
#include <sstream>
#include <regex.h>

class Date{
	private:
		unsigned int year;
		unsigned int month;
		unsigned int day;
	public:
		Date(std::string year, std::string month, std::string day);
		unsigned int getYear() const;
		unsigned int getMonth() const;
		unsigned int getDay() const;
		void setYear(unsigned int year);
		void setMonth(unsigned int month);
		void setDay(unsigned int day);
};

#endif
