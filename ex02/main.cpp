#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed d;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << d << std::endl;
	std::cout << --d << std::endl;
	std::cout << d << std::endl;
	std::cout << d-- << std::endl;
	std::cout << c << std::endl;
	std::cout << a + b << std::endl;
	std::cout << Fixed::max(a, d) << std::endl;
	std::cout << Fixed::min(c, b) << std::endl;
	return 0;
}