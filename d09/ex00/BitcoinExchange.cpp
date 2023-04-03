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

bool Date::operator==(const Date &date) const{
	if (this->year == date.year && this->month == date.month && this->day == date.day)
		return true;
	return false;
}

bool Date::operator<(const Date& other) const {
    if (this->year != other.year) {
        return year < other.year;
    }
    if (this->month != other.month) {
        return month < other.month;
    }
    return this->day < other.day;
}

std::ostream &operator<<(std::ostream& os, const Date& date) {
	os << date.getYear() << "-";
	if (date.getMonth() < 10)
		std::cout << "0" << date.getMonth() << "-";
	else
		std::cout << date.getMonth() << "-";
	if (date.getDay() < 10)
		std::cout << "0" << date.getDay();
	else
		std::cout << date.getDay();
	return os;
}

BitcoinExchange::BitcoinExchange(Date &date, double &price, e_type type) {
	if (type == DATA && price < 0)
		throw std::runtime_error("Negative rate exchange");
	else if (type == INPUT && price < 0)
		throw std::runtime_error("not a positive number.");
	else if (type == INPUT && price > 1000)
		throw std::runtime_error("too large a number.");
	bitcoinExchange.insert(std::pair<Date, double>(date, price));
}

Date const &BitcoinExchange::getDate(Date date) const {
	std::map<Date, double>::const_iterator beginIt = bitcoinExchange.begin();
	Date ret;
	std::map<Date, double>::const_iterator it = bitcoinExchange.begin();
	while (it != bitcoinExchange.end())
	{
		if (it->first == date)
			return it->first;
		it++;
	}
	it--;
	if (it != beginIt)
	{
		it--;
		return (it->first);
	}
	else
		throw std::runtime_error("date doesn't exist");
}

double const &BitcoinExchange::getValue(Date &date) const {
	std::map<Date, double>::const_iterator it = bitcoinExchange.find(date);
	return it->second;
}

std::map<Date, double> const &BitcoinExchange::getMap() const {
	return bitcoinExchange;
}
