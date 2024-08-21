#include "Fixed.hpp"
#include <iostream>

// デフォルトコンストラクタ：固定小数点値を0に初期化
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// コピーコンストラクタ：他のFixedオブジェクトを元に新しいFixedオブジェクトを初期化
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // コピー代入演算子を使用して値をコピー
}

// コピー代入演算子：他のFixedオブジェクトの値をこのオブジェクトにコピー
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // 自己代入を防ぐためのチェック
	{
		this->_fixedPointValue = other.getRawBits(); // 生の固定小数点値をコピー
	}
	return *this;
}

// デストラクタ：オブジェクトが破棄されるときに呼び出される
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// 生の固定小数点値を取得する関数
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// 生の固定小数点値を設定する関数
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
