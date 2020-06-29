#ifndef POINT_HPP
#define POINT_HPP

#ifdef POINT_EXPORTS
  #define POINTAPI __declspec(dllexport)
#else
  #define POINTAPI __declspec(dllimport)
#endif

#include <ostream>

using std::ostream;

class POINTAPI Point
{
  public:
    // Constructors.
    Point();
    Point(int x, int y);

    // Getters and setters.
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    // Friend the overloaded operators, so they can access private Point data.
    friend Point operator+(const Point& lhs, const Point& rhs);
    friend ostream& operator<<(ostream& os, const Point& pt);

  private:
    int x, y;
};

// Overloaded operators.
POINTAPI Point operator+(const Point& lhs, const Point& rhs);
POINTAPI ostream& operator<<(ostream& os, const Point& pt);

extern POINTAPI Point foo;
extern POINTAPI Point bar;

#endif
