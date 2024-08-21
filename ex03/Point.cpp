#include "Point.hpp"

// デフォルトコンストラクタ、xとyを0に初期化
Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// 座標(x, y)を指定するコンストラクタ
Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Constructor with parameters called" << std::endl;
}

// コピーコンストラクタ
Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
	// std::cout << "Copy constructor called" << std::endl;
}

// コピー代入演算子
Point &Point::operator=(const Point &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// const_castを使用して定数メンバを変更
		const_cast<Fixed &>(this->_x) = other.getX();
		const_cast<Fixed &>(this->_y) = other.getY();
	}
	return *this;
}

// デストラクタ
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// x座標を取得するメソッド
Fixed Point::getX() const
{
	return this->_x;
}

// y座標を取得するメソッド
Fixed Point::getY() const
{
	return this->_y;
}
