#include "Fixed.hpp"
#include <cmath>

// デフォルトコンストラクタ：固定小数点の値を0に初期化
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// 整数を固定小数点に変換するコンストラクタ
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits; // 整数値を左シフトして固定小数点形式に変換
}

// 浮動小数点数を固定小数点に変換するコンストラクタ
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits)); // 浮動小数点数を固定小数点形式に変換
}

// コピーコンストラクタ：別のFixedオブジェクトをコピー
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // コピー代入演算子を使用して値をコピー
}

// コピー代入演算子：別のFixedオブジェクトの値をコピー
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // 自己代入チェック
	{
		this->_fixedPointValue = other.getRawBits(); // 生の固定小数点値をコピー
	}
	return *this;
}

// デストラクタ：オブジェクトが破棄される際に呼び出される
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

// 固定小数点値を浮動小数点数に変換する関数
float Fixed::toFloat() const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// 固定小数点値を整数に変換する関数
int Fixed::toInt() const
{
	return _fixedPointValue >> _fractionalBits; // 右シフトして整数部分を取得
}

// std::ostreamにFixedオブジェクトを出力するためのオーバーロード
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat(); // 浮動小数点数として出力
	return out;
}
