#include <iostream>
#include <string>
#include <sstream>
#include <locale>

void print_upper_str(std::string str)
{
	std::locale loc;
	int i;

	for (std::string::size_type i = 0; i < str.length(); ++i)
		std::cout << std::toupper(str[i], loc);
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	std::string str1("shhhhh... I think the students are asleep...");
	std::string str2("Damnit ! Sorry students, I thought this thing was off.");
	std::string input;
	std::stringstream ss;
	int	i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac == 2)
		print_upper_str(av[1]);
	else
	{
		i = 1;
		while (i < ac)
		{
			ss << av[i];
			i++;
		}
		input = ss.str();
		print_upper_str(input);
	}
	return 0;
}
