#ifndef _PLANET_H_
#define _PLANET_H_
#include "Ship.h"
#include <string>
class Planet{
  friend ostream& operator<<(ostream &os, const Planet &p);
private:
  string name;
  vector <Base> bases;
  vector <Ship> ships;
  int searchBase(string name) const;
  int searchShip(string name) const;
  int findLargestFreeShip() const;
  int findLargestAvaliableBase(int shipIndex) const;
  int closestBaseToCentroid(Ship ship) const;
  void assignRemainingBases(int shipIndex);
  int askPeople(bool opt);
  int askEquipment(bool opt);
  Coordinate askCoordinates();
  void modifyBase(int basePos);
public:
  Planet(string name);
  string getName() const { return name; }
  unsigned getNumBases() const { return bases.size(); }
  Base getBase(unsigned pos) const { return bases[pos]; }
  unsigned getNumShips() const { return ships.size(); }
  Ship getShip(unsigned pos) const { return ships[pos]; }
  void createBase(string name = "");
  void createShip();
  void deleteBase(string name = "");
  void deleteShip(string name = "");
  void evacuationPlan();
};
#endif
