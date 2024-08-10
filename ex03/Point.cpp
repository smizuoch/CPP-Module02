#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Constructor with parameters called" << std::endl;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		const_cast<Fixed &>(this->_x) = other.getX();
		const_cast<Fixed &>(this->_y) = other.getY();
	}
	return *this;
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}
