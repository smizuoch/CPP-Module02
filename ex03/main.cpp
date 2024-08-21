#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point p1(1, 1);   // 三角形の内側
	Point p2(11, 11); // 三角形の外側

	if (bsp(a, b, c, p1))
		std::cout << "Point p1 is inside the triangle" << std::endl;
	else
		std::cout << "Point p1 is outside the triangle" << std::endl;

	if (bsp(a, b, c, p2))
		std::cout << "Point p2 is inside the triangle" << std::endl;
	else
		std::cout << "Point p2 is outside the triangle" << std::endl;

	// 各三角形と点に対して bsp 関数を使って、その点が三角形の内部にあるかどうかを判定する
	std::cout << std::boolalpha

	          << "a(0, 0), b(0, 5), c(5, 0), point(1, 1): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1))
	          << std::endl

	          << "a(0, 0), b(0, 5), c(5, 0), point(0, 5): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5))
	          << std::endl

	          << "a(0, 0), b(0, 5), c(5, 0), point(0, 3): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3))
	          << std::endl

	          << "a(0, 0), b(0, 5), c(5, 0), point(0, 0): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0))
	          << std::endl

	          << "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
	          << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

	          << "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
	          << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

	          << "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
	          << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;

	return 0;
}
