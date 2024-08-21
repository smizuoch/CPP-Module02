#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// Fixedクラスの定義
class Fixed
{
  private:
	int _fixedPointValue;                 // 固定小数点の生データを格納するメンバ変数
	static const int _fractionalBits = 8; // 固定小数点の小数部のビット数を定義

  public:
	Fixed();                              // デフォルトコンストラクタ
	Fixed(const int intValue);            // 整数を引数にとるコンストラクタ
	Fixed(const float floatValue);        // 浮動小数点数を引数にとるコンストラクタ
	Fixed(const Fixed &other);            // コピーコンストラクタ
	Fixed &operator=(const Fixed &other); // コピー代入演算子
	~Fixed();                             // デストラクタ

	int getRawBits() const;         // 生の固定小数点値を取得する関数
	void setRawBits(int const raw); // 生の固定小数点値を設定する関数
	float toFloat() const;          // 固定小数点値を浮動小数点数に変換する関数
	int toInt() const;              // 固定小数点値を整数に変換する関数
};

// std::ostreamにFixedオブジェクトを出力するためのオーバーロード
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
