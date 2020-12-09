#ifndef _SHIP_H_
#define _SHIP_H_
#include <vector>
#include "Base.h"
class Ship{
  friend ostream& operator<<(ostream &os, const Ship& s);
private:
  string name;
  int maxPeople, maxEquipment;
  static unsigned MinShipPeople;
  int curPeople, curEquipment;
  vector<Base*> bases;
public:
  Ship(string name, int maxPeople, int maxEquipment);
  string getName() const { return name; }
  int getMaxPeople() const { return maxPeople; }
  int getMaxEquipment() const { return maxEquipment; }
  int getCurPeople() const { return curPeople; }
  int getCurEquipment() const { return curEquipment; }
  void setMaxPeople(int maxPeople);
  void setMaxEquipment(int maxEquipment);
  bool hasBases() const { return !(bases.size() == 0); }
  unsigned numBases() const { return bases.size(); }
  Base* getBase(unsigned pos) const;
  bool admitsBase(const Base& base) const;
  void addBase(Base* pbase);
  Coordinate centroid() const;
  void detachBases();
};
#endif
