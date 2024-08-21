#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

// 2D空間上の点を表すクラス
class Point
{
  private:
	Fixed const _x; // x座標
	Fixed const _y; // y座標

  public:
	Point();                              // デフォルトコンストラクタ
	Point(const float x, const float y);  // 座標を指定するコンストラクタ
	Point(const Point &other);            // コピーコンストラクタ
	Point &operator=(const Point &other); // コピー代入演算子
	~Point();                             // デストラクタ

	Fixed getX() const; // x座標を取得するメソッド
	Fixed getY() const; // y座標を取得するメソッド
};

#endif
