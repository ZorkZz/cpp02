#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(float value)
{
	_value = value * (1 << _fractional_bit);
}
Fixed::Fixed(int value)
{
	this->_value = value << this->_fractional_bit;
}

Fixed::Fixed(const Fixed &fixed)
{
	_value = fixed._value;
}

int Fixed::operator != (const Fixed &fixed)
{
	if (this->toFloat() != fixed.toFloat())
		return (1);
	return (0);
}

int Fixed::operator == (const Fixed &fixed)
{
	if (this->toFloat() == fixed.toFloat())
		return (1);
	return (0);
}

int Fixed::operator <= (const Fixed &fixed)
{
	if (this->toFloat() <= fixed.toFloat())
		return (1);
	return (0);
}

int Fixed::operator >= (const Fixed &fixed)
{
	if (this->toFloat() >= fixed.toFloat())
		return (1);
	return (0);
}

int Fixed::operator > (const Fixed &fixed)
{
	if (this->toFloat() > fixed.toFloat())
		return (1);
	return (0);
}

int Fixed::operator < (const Fixed &fixed)
{
	if (this->toFloat() < fixed.toFloat())
		return (1);
	return (0);
}

Fixed	&Fixed::operator = (const Fixed &fixed)
{
	if (this != &fixed)
		this->_value = fixed._value;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed)
{
	if (fixed.toFloat() != 0)
		return Fixed(this->toFloat() / fixed.toFloat());
	return (Fixed(this->toFloat()));
	
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

std::ostream	&operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed()
{
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_fractional_bit));
}

int	Fixed::toInt(void) const
{
	return((this->_value >> this->_fractional_bit));
}

Fixed	Fixed::min( const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return (Fixed( fixed2 ));
	return (Fixed( fixed1 ));
}

Fixed	Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return (Fixed( fixed2 ));
	return (Fixed( fixed1 ));
}

Fixed	Fixed::max( const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (Fixed( fixed1 ));
	return (Fixed( fixed2 ));
}

Fixed	Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (Fixed( fixed1 ));
	return (Fixed( fixed2 ));
}
