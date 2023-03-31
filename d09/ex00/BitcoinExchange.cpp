#include "BitcoinExchange.hpp"

unsigned int	strToInt(std::string str)
{
	unsigned int n;
	std::stringstream ss(str);
	ss >> n;
	if (!ss.eof() || ss.fail())
		throw   std::runtime_error("Invalid date");
	return n;
}

Date::Date(std::string yearString, std::string monthString, std::string dayString)
{
	year = strToInt(yearString);
	month = strToInt(monthString);
	day = strToInt(dayString);
	if (year < 1 || month < 1 || day < 1)
		throw std::runtime_error("Invalid date");
	if (strlen(yearString.c_str()) != 4 || strlen(monthString.c_str()) != 2 || strlen(dayString.c_str()) != 2)
		throw std::runtime_error("Invalid date");
	if (month > 12 || day > 31 || (year%4 && month == 2 && day > 29) || (!(year%4) && month==2 && day > 28) || (month == 4 && day > 30) || (month == 6 && day > 30) || (month == 9 && day > 30) || (month == 11 && day > 30) || year > 2023)
		throw std::runtime_error("Invalid date");
}

unsigned int Date::getDay() const {
	return day;
}

unsigned int Date::getMonth() const {
	return month;
}

unsigned int Date::getYear() const {
	return year;
}

void	Date::setDay(unsigned int day) {
	this->day = day;
}

void	Date::setMonth(unsigned int month) {
	this->month = month;
}

void Date::setYear(unsigned int year) {
	this->year = year;
}
