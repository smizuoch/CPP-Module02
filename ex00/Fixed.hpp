#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
  private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

  public:
	Fixed();                              // デフォルトコンストラクタ
	Fixed(const Fixed &other);            // コピーコンストラクタ
	Fixed &operator=(const Fixed &other); // コピー代入演算子
	~Fixed();                             // デストラクタ

	int getRawBits() const;         // 生の固定小数点値を取得
	void setRawBits(int const raw); // 生の固定小数点値を設定
};

#endif
