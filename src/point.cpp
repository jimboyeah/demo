
#include "point.hpp"

Point::Point()
  : x(0), y(0)
{ }

Point::Point(int x, int y)
  : x(x), y(y)
{ }

int Point::getX() const { return this->x; }

int Point::getY() const { return this->y; }

void Point::setX(int x) { this->x = x; }

void Point::setY(int y) { this->y = y; }

Point operator+(const Point& lhs, const Point& rhs)
{
  return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

ostream& operator<<(ostream& os, const Point& pt)
{
  return os << "(" << pt.x << ", " << pt.y << ")";
}

Point foo(9, 6);
Point bar(3, 19);