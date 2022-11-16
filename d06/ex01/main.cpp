#include "Data.hpp"

int main()
{
    Data *test = new Data;

    std::cout << "Before:" << std::endl;
    std::cout << *test;

    test = deserialize(serialize(test));

    std::cout << "After:" << std::endl;
    std::cout << *test;

   delete test; 

   return 0;
}
