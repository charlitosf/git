#ifndef _COORDINATE_H_
#define _COORDINATE_H_
#include <iostream>

using namespace std;

class Coordinate{
  friend ostream& operator<< (ostream &os, const Coordinate& c);
  friend istream& operator>> (istream &is, Coordinate& c);
private:
  double x,y;
public:
  Coordinate();
  Coordinate(double x, double y);
  double getX() const { return x; }
  double getY() const { return y; }
  double distance(const Coordinate &c) const;
};

#endif
