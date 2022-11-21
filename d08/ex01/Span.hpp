#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <limits>
# include <vector>
# include <algorithm>
# include <climits>

class Span
{

	public:

		Span(unsigned int N);
		Span( Span const & src );
		~Span();
		class ImpossibleToStore : public std::exception
		{
			public :
				virtual const char* what() const throw()
				{
					return ("Span is already full!\n");
				}
		};

		Span &		operator=( Span const & rhs );

		void		addNumber(int number);
		int			shortestSpan();
		int			longestSpan();
		int			addNumber();


	private:

		Span();
		unsigned int		_max_to_store;
		std::vector<int>	_array;

};

// std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */
