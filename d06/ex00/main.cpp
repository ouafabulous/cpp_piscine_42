#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cerrno>
#include <iomanip>
#include <limits>
#include <cfloat>
#include <cmath>

#define ERROR_MSG "Usage: ./convert ARG. ARG can only be a digit or a 1 letter character.\n"

int check_negative(const char *av1)
{
    while (*av1 == ' ' || *av1 == '\f')
    {
        av1++;
    }
    if (*av1 == '-')
    {
        return (1);
    }
    return (0);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << ERROR_MSG;
    }
    else
    {
        int my_int;
        float my_float;
        char temp_char;
        std::string my_char;
        double my_double;
        char *pEnd = (char *)argv[1];

        my_double = strtod(argv[1], &pEnd);
        if (pEnd == argv[1])
        {
            std::string pEnd_str;
            std::istringstream iss(pEnd);
            iss >> std::ws >> pEnd_str;
            if (pEnd_str.length() == 1)
            {
                my_double = static_cast<double>(pEnd_str[0]);
            }
            else
            {
                std::cout << ERROR_MSG;
                return (1);
            }
        }
        else
        {
            while (*pEnd == ' ' || *pEnd == '\t')
            {
                pEnd++;
            }
            std::string pEnd_str(pEnd);
            if (pEnd_str.length() > 1 || (pEnd_str[0] != '\0' && pEnd_str[0] != 'f'))
            {
                std::cout << ERROR_MSG;
                return (1);
            }
        }
        my_float = static_cast<float>(my_double);
        my_int = static_cast<int>(my_double);
        if (my_int > 127 || my_int < 0)
        {
            my_char = "Impossible";
        }
        else if (my_int >= 0 && my_int <= 31)
        {
            my_char = "Non displayable";
        }
        else
        {
            temp_char = my_int;
            my_char += temp_char;
        }
        std::cout << "Char: " << my_char << std::endl;
        if (std::isnan(my_double))
        {
            std::cout << "Int: "
                      << "Impossible" << std::endl;
        }
        else
        {
            std::cout << "Int: " << my_int << std::endl;
        }
        std::cout << std::fixed << "Float: " << std::setprecision(1) << my_float << "f" << std::endl;
        std::cout << "Double: " << my_double << std::endl;
    }
    return 0;
}
