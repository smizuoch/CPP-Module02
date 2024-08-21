#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;               // デフォルトコンストラクタ呼び出し
	Fixed const b(10);     // 整数コンストラクタ呼び出し
	Fixed const c(42.42f); // 浮動小数点コンストラクタ呼び出し
	Fixed const d(b);      // コピーコンストラクタ呼び出し

	a = Fixed(1234.4321f); // コピー代入演算子呼び出し

	// 各オブジェクトの値を出力
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	// 各オブジェクトの整数値を出力
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
