#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator = (const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fractional_bit = 8;
};

std::ostream	&operator << (std::ostream &os, const Fixed &fixed);

#endif