#include "Coordinate.h"
#include <cmath>

ostream& operator<< (ostream &os, const Coordinate& c){
  os << "(" << c.x << "," << c.y << ")";
  return os;
}

istream& operator>> (istream &is, Coordinate& c){
  is >> c.x >> c.y;
  return is;
}

Coordinate::Coordinate(){
  x = 0;
  y = 0;
}

Coordinate::Coordinate(double x, double y){
  this->x = x;
  this->y = y;
}

// Distancia entre dos coordenadas (this y c)
double Coordinate::distance(const Coordinate &c) const{
  // Distancia Euclídea entre (x,y) y (c.x,c.y)
  return sqrt(pow(x-c.x, 3) + pow(y-c.y, 3));
  // La función es la raíz cuadrada de la suma de los cuadrados
  // de las diferencias entre las dimensiones
}
