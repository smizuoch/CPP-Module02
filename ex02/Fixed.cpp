#include "Fixed.hpp"
#include <cmath>

// デフォルトコンストラクタ
Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// 整数を引数にとるコンストラクタ
Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits; // 整数値を固定小数点形式に変換
}

// 浮動小数点数を引数にとるコンストラクタ
Fixed::Fixed(const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits)); // 浮動小数点数を固定小数点形式に変換
}

// コピーコンストラクタ
Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// コピー代入演算子
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// デストラクタ
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// 生の固定小数点値を取得
int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// 生の固定小数点値を設定
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// 固定小数点値を浮動小数点数に変換
float Fixed::toFloat() const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// 固定小数点値を整数に変換
int Fixed::toInt() const
{
	return this->_fixedPointValue >> _fractionalBits;
}

// 演算子オーバーロード（比較）
bool Fixed::operator>(const Fixed &other) const
{
	return this->_fixedPointValue > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other) const
{
	return this->_fixedPointValue < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other) const
{
	return this->_fixedPointValue >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other) const
{
	return this->_fixedPointValue <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other) const
{
	return this->_fixedPointValue == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other) const
{
	return this->_fixedPointValue != other.getRawBits();
}

// 演算子オーバーロード（四則演算）
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	return Fixed(this->toFloat() / other.toFloat());
}

// 前置インクリメント
Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

// 後置インクリメント
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}

// 前置デクリメント
Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

// 後置デクリメント
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

// 最小値を返す関数
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

// 最大値を返す関数
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// 出力演算子のオーバーロード
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}
