#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(float value)
{
	std::cout << "Copy constructor float called" << std::endl;
	_value = value * (1 << _fractional_bit);
}
Fixed::Fixed(int value)
{
	std::cout << "Copy constructor int called" << std::endl;
	this->_value = value << this->_fractional_bit;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = fixed._value;
}


Fixed	&Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed._value;
	return (*this);
}

std::ostream	&operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
