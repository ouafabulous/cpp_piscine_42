#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFound : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Element not found!\n");
		}
};

template <typename Container>
int	easyFind(Container &where_to_find, int to_find)
{
	int	found_or_not = *find(where_to_find.begin(), where_to_find.end(), to_find);
	if (found_or_not == *where_to_find.end()) {
		throw NotFound();
	}
	return (found_or_not);
}

#endif
