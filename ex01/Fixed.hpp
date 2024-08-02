#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

  public:
	Fixed();                              // デフォルトコンストラクタ
	Fixed(const int intValue);            // 整数を引数にとるコンストラクタ
	Fixed(const float floatValue);        // 浮動小数点数を引数にとるコンストラクタ
	Fixed(const Fixed &other);            // コピーコンストラクタ
	Fixed &operator=(const Fixed &other); // コピー代入演算子
	~Fixed();                             // デストラクタ

	int getRawBits() const;         // 生の固定小数点値を取得
	void setRawBits(int const raw); // 生の固定小数点値を設定
	float toFloat() const;          // 固定小数点値を浮動小数点数に変換
	int toInt() const;              // 固定小数点値を整数に変換
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
