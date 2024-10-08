#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
	int _fixedPointValue;                 // 固定小数点の値を格納するためのメンバ変数
	static const int _fractionalBits = 8; // 小数部のビット数を指定（8ビット）

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

	// 演算子オーバーロード
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const; // 加算
	Fixed operator-(const Fixed &other) const; // 減算
	Fixed operator*(const Fixed &other) const; // 乗算
	Fixed operator/(const Fixed &other) const; // 除算

	Fixed &operator++();   // 前置インクリメント
	Fixed operator++(int); // 後置インクリメント
	Fixed &operator--();   // 前置デクリメント
	Fixed operator--(int); // 後置デクリメント

	static Fixed &min(Fixed &a, Fixed &b);                   // 最小値を返す
	static const Fixed &min(const Fixed &a, const Fixed &b); // 最小値を返す（定数版）
	static Fixed &max(Fixed &a, Fixed &b);                   // 最大値を返す
	static const Fixed &max(const Fixed &a, const Fixed &b); // 最大値を返す（定数版）
};

std::ostream &operator<<(std::ostream &out, const Fixed &value); // 出力演算子のオーバーロード

#endif
