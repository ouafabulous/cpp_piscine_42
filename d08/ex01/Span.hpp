#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
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
					return ("Span is full!\n");
				}
		};
		class NoSpanFound : public std::exception
		{
			public :
				virtual const char * what() const throw()
				{
					return ("Span has got less or equal to one elemen. Can't find shortest/longest span!\n");
				}
		};

		Span &		operator=( Span const & rhs );

		void			addNumber(int number);
		int				shortestSpan();
		int				longestSpan();
		void			addNumber();
		template <typename inputIt>
		void			addNumber(inputIt begin, inputIt end)
		{
			for (int i = 0; i != end - begin; i++) {
				addNumber(*(begin + i));
			}
		};
		int				getArrayValue(unsigned int i) const;
		unsigned int	getArraySize() const;

	private:

		Span();
		unsigned int		_max_to_store;
		std::vector<int>	_array;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */
