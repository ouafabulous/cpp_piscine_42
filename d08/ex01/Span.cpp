#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() {}

Span::Span(unsigned int N) : _max_to_store(N) {}

Span::Span( const Span & src )
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

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_max_to_store = rhs._max_to_store;
		this->_array = rhs._array;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Span const & i )
// {
	//o << "Value = " << i.getValue();
	// return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Span::addNumber(int number)
{
	if (_array.size() == _max_to_store) {
		throw ImpossibleToStore();
	}
	_array.push_back(number);
}

void				Span::addNumber(int array[])
{
	_array.insert(_array.end(), array);
}


int					Span::shortestSpan()
{
	// int	min = *std::min_element(_array.begin(), _array.end());
	// std::nth_element(_array.begin(), _array.begin() + 1,_array.end() );
	// int	second_min = _array[1];
	// std::nth_element(_array.begin(), _array.begin() + 1, _array.end(), std::greater<int>());
	// int	second_max = _array[1];
	if (_array.size() <= 1) {
		throw NoSpanFound();
	}
	int	shortest_span = INT_MAX;
	for (int i = 0; i != _array.size() - 1; i++)
	{
		for (int j = i + 1; j != _array.size(); j++)
		{
			if(abs(_array[i] - _array[j]) < shortest_span) {
				shortest_span = abs(_array[i] - _array[j]);
			}
		}
	}
}

int					Span::longestSpan()
{
	if (_array.size() <= 1) {
		throw NoSpanFound();
	}
	int	min = *std::min_element(_array.begin(), _array.end());
	int	max = *std::max_element(_array.begin(), _array.end());
	return (max - min);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */