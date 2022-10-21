#include <string>
#include <iostream>

#define DEBUG_MSG "[ DEBUG ]" << std::endl <<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl << "I really do !"
#define INFO_MSG "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define WARNING_MSG "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month."
#define ERROR_MSG "[ ERROR ]" << std::endl << "This is unacceptable !" << std::endl << "I want to speak to the manager now."
#define OTHER_MSG "[ Probably complaining about insignificant problems ]"

#define YELLOW  "\033[1m\033[33m"
#define MAGENTA "\033[1m\033[35m"
#define BLUE    "\033[1m\033[34m"
#define RED     "\033[1m\033[31m"
#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"

class Harl
{

private:

	typedef void (Harl::*Func)(void) const;

	enum {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NUMBER};

	static const char *_level[NUMBER];
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;
	Func	_tab[NUMBER];

public:

	Harl();
	~Harl();

	void	complain(std::string level) const;
};
