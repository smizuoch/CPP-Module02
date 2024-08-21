#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;    // デフォルトコンストラクタを使用してFixedオブジェクトを作成
	Fixed b(a); // コピーコンストラクタを使用してFixedオブジェクトを作成
	Fixed c;    // デフォルトコンストラクタを使用してFixedオブジェクトを作成

	c = b; // コピー代入演算子を使用してbをcにコピー

	// 各オブジェクトの生の固定小数点値を出力
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
