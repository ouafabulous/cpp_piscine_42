#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int ac, char **av)
{

	if (ac == 4)
	{
		std::ifstream		ifs(av[1]);
		std::string			infile_name(av[1]);
		std::string			outfile_name = infile_name + ".replace";
		std::string			to_replace(av[2]);
		std::string			replace_by(av[3]);
		std::stringstream	buffer;
		std::string			file_content;
		int					index;

		if (not ifs.good()) {
			std::cout << "File Error." << std::endl << "1- Check if the file exists." << std::endl << "2- Check its permissions." << std::endl;
			return (1);
		}

		if (to_replace == "") {
			std::cout << "substring to replace shouldn't be an empty string!" << std::endl;
			return (1);
		}

		std::ofstream		ofs(outfile_name.c_str());

		if (not ofs.good()) {
			std::cout << "Couldn't create <output_file>" << std::endl;
			return (1);
		}

		buffer << ifs.rdbuf();
		file_content = buffer.str();

		while (true) {
			index = file_content.find(to_replace);
			if (index < 0) {
				ofs << file_content;
				break;
			}
			file_content.erase(index, to_replace.length());
			file_content.insert(index, replace_by);
			index += replace_by.length();
			ofs << file_content.substr(0, index);
			file_content = std::string (&(file_content[index]));
		}


	}
	else
		std::cout << "Usage: ./exe <filename> str1 str2" << std::endl;
	return 0;
}
