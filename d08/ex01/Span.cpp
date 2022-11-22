#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() {}

Span::Span(unsigned int N) : _max_to_store(N) {}

Span::Span(const Span &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_max_to_store = rhs._max_to_store;
		this->_array = rhs._array;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Span const &i)
{
	std::cout << "Elements contained in your Span: ";
	for (unsigned int j = 0; j != i.getArraySize(); j++)
	{
		std::cout << i.getArrayValue(j) << " ";
	}
	std::cout << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int number)
{
	if (_array.size() == _max_to_store)
	{
		throw ImpossibleToStore();
	}
	_array.push_back(number);
}

int Span::shortestSpan()
{
	if (_array.size() <= 1)
	{
		throw NoSpanFound();
	}
	int shortest_span = INT_MAX;
	for (unsigned int i = 0; i != _array.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j != _array.size(); j++)
		{
			if (abs(_array[i] - _array[j]) < shortest_span)
			{
				shortest_span = abs(_array[i] - _array[j]);
			}
		}
	}
	return (shortest_span);
}

int Span::longestSpan()
{
	if (_array.size() <= 1)
	{
		throw NoSpanFound();
	}
	int min = *std::min_element(_array.begin(), _array.end());
	int max = *std::max_element(_array.begin(), _array.end());
	return (max - min);
}

int Span::getArrayValue(unsigned int i) const
{
	return (_array[i]);
}

unsigned int Span::getArraySize() const
{
	return (_array.size());
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
