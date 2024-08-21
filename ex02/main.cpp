#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;               // デフォルトコンストラクタを使用してFixedオブジェクトを作成
	Fixed const b(10);     // 整数を使用してFixedオブジェクトを作成
	Fixed const c(42.42f); // 浮動小数点数を使用してFixedオブジェクトを作成
	Fixed const d(b);      // コピーコンストラクタを使用してFixedオブジェクトを作成

	a = Fixed(1234.4321f); // 代入演算子を使用してオブジェクトaに新しい値を割り当て

	// 各オブジェクトの値を出力
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	// 各オブジェクトを整数として出力
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
