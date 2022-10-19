#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int ac, char **av)
{
	int		i;
	int		len_s1;
	char	c;

	if (ac == 4)
	{
		std::ifstream		ifs(av[1]);
		std::string			new_av1(av[1]);
		std::string			new_av2(av[2]);
		std::string			new_av3(av[3]);
		std::stringstream	to_copy_stream;
		std::string			to_copy;

		len_s1 = new_av2.length();
		if (ifs.fail()) {
			std::cout << "File Error" << std::endl << "1- Check if the file exists Does" << std::endl << "2- Check its permissions" << std::endl;
			return (1);
		}
		new_av1 += ".replace";
		std::ofstream	ofs(new_av1.c_str());
		if (ofs.fail()) {
			std::cout << "Couldn't create <output_file>" << std::endl;
			return (1);
		}
		while (1) {
			i = 0;
			while (i < len_s1 - 1) {
				to_copy_stream << std::flush;
				if (!ifs.get(c))
				{
					ofs << to_copy_stream.rdbuf();
					exit (0);
				}
				to_copy_stream << c;
				i++;
			}
			if (!new_av2.compare(to_copy_stream.str())) {
				ofs << new_av3;
			}
		}
	}
	else
		std::cout << "Usage: ./exe <filename> str1 str2" << std::endl;
	return 0;
}
