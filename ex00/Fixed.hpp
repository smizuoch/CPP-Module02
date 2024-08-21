#ifndef FIXED_HPP
#define FIXED_HPP

// Fixedクラスの宣言
class Fixed
{
  private:
	int _fixedPointValue;                 // 固定小数点の生の値
	static const int _fractionalBits = 8; // 固定小数点の小数部のビット数（8ビット）

  public:
	Fixed();                              // デフォルトコンストラクタ
	Fixed(const Fixed &other);            // コピーコンストラクタ
	Fixed &operator=(const Fixed &other); // コピー代入演算子
	~Fixed();                             // デストラクタ

	int getRawBits() const;         // 生の固定小数点値を取得するメンバ関数
	void setRawBits(int const raw); // 生の固定小数点値を設定するメンバ関数
};

#endif
