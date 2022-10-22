#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed(int const integral);
		Fixed(float const fractional);
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );

		int			getRawBits(void) const;
		int			setRawBits(int const raw);

		float		toFloat(void) const;
		int			toInt(void) const;

	private:

		int					_integral;
		static const int	_fractional;

};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */
