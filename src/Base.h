#ifndef _BASE_H_
#define _BASE_H_
#include <iostream>
#include "Coordinate.h"
#include "Util.h"

using namespace std;

class Base{
  friend ostream& operator<<(ostream &os, const Base& b);
private:
  string name;
  int people, equipment;
  static unsigned MinBasePeople;
  bool assigned;
  Coordinate position;
public:
  Base(string name, const Coordinate& position, int people, int equipment);
  string getName() const { return name; }
  Coordinate getPosition() const;
  int getPeople() const { return people; }
  int getEquipment() const { return equipment; }
  bool isAssigned() const { return assigned; }
  void setPosition(const Coordinate& position);
  void setPeople(int people);
  void setEquipment(int equipment);
  void setAssigned(bool assigned) { this->assigned = assigned; }
};
#endif
