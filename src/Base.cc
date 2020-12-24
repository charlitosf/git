#include "Base.h"

unsigned Base::MinBasePeople = 50;

ostream& operator<<(ostream &os, const Base& b){
  os << "[(" << b.name << ") " << b.people << " " << b.equipment << " "
      << b.position << " " << b.assigned << "]" << endl;
  return os;
}

Base::Base(string name, const Coordinate& position, int people, int equipment){
  if(people <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else if((unsigned)people < MinBasePeople){
    throw ERR_LOW_PEOPLE;
  }
  else if(equipment <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else{
    this->name = name;
    this->position = position;
    this->people = people;
    this->equipment = equipment;
    assigned = false;
  }
}

Coordinate Base::getPosition() const{
  Coordinate c(position.getX(), position.getY());
  return c;
}

void Base::setPosition(const Coordinate& position){
  this->position = position;
}

void Base::setPeople(int people){
  if(people <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else if((unsigned)people < MinBasePeople){
    throw ERR_LOW_PEOPLE;
  }
  else{
    this->people = people;
  }
}

void Base::setEquipment(int equipment){
  if(equipment <= 0){
    throw ERR_WRONG_NUMBER;
  }
  else{
    this->equipment = equipment;
  }
}
