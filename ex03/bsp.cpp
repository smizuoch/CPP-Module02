#include "Point.hpp"

// 三角形の面積を求めるための補助関数
// 三つの点のうち、どれがどちら側にあるかを計算する
static Fixed sign(Point const p1, Point const p2, Point const p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// 三角形の中に点が含まれているかどうかを判定する関数
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;
	bool has_neg, has_pos;

	// 各三角形の面積を求める
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	// 点が三角形の外側にあるかどうかをチェック
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	// 点が三角形の内部にある場合はtrueを返す
	return !(has_neg && has_pos);
}

// https://en.wikipedia.org/wiki/Barycentric_coordinate_system