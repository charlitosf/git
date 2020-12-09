#include "Ship.h"

unsigned Ship::MinShipPeople = 100;

ostream& operator<<(ostream &os, const Ship& s){
  os << "[(" << s.name << ") " << s.maxPeople << "{" << s.curPeople
      << "} " << s.maxEquipment << "{" << s.curEquipment << "}]" << endl;
  for(unsigned i = 0; i < s.bases.size(); i++){
    os << "  ";
    os << *s.bases[i];
  }
  return os;
}

Ship::Ship(string name, int maxPeople, int maxEquipment){
  if(maxPeople <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else if((unsigned)maxPeople < MinShipPeople){
    throw ERR_LOW_PEOPLE;
  }
  else if(maxEquipment <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else{
    this->name = name;
    this->maxPeople = maxPeople;
    this->maxEquipment = maxEquipment;
    curPeople = curEquipment = 0;
  }
}
void Ship::setMaxPeople(int maxPeople){
  if(maxPeople <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else if((unsigned)maxPeople < MinShipPeople){
    throw ERR_LOW_PEOPLE;
  }
  else{
    this->maxPeople = maxPeople;
  }
}
void Ship::setMaxEquipment(int maxEquipment){
  if(maxEquipment <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else{
    this->maxEquipment = maxEquipment;
  }
}

Base* Ship::getBase(unsigned pos) const{
  if(pos < bases.size()){
    return bases[pos];
  }
  else{
    return NULL;
  }
}

bool Ship::admitsBase(const Base& base) const{
  return (base.getPeople() <= (maxPeople-curPeople) &&
      base.getEquipment() <=(maxEquipment - curEquipment) && !base.isAssigned());
}

void Ship::addBase(Base* pbase){
  curPeople += pbase->getPeople();
  curEquipment += pbase->getEquipment();
  pbase->setAssigned(true);
  bases.push_back(pbase);
}

Coordinate Ship::centroid() const{
  double xc = 0, yc = 0;
  if(bases.size() > 0){
    for(unsigned i = 0; i < bases.size(); i++){
      Coordinate c = bases[i]->getPosition();
      xc += c.getX();
      yc += c.getY();
    }
    xc /= bases.size();
    yc /= bases.size();
  }
  Coordinate c(xc,yc);
  return c;
}

void Ship::detachBases(){
  for(unsigned i = 0; i < bases.size(); i++){
    bases[i]->setAssigned(false);
  }
  bases.clear();
  curPeople = curEquipment = 0;
}
