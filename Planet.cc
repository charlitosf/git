#include "Planet.h"

ostream& operator<<(ostream &os, const Planet &p) {
	os << "Planet: " << p.name << endl;
	os << "Ships:" << endl;
	for (unsigned i = 0; i < p.ships.size(); i++) {
		os << p.ships[i];
	}
	os << "Bases:" << endl;
	for (unsigned i = 0; i < p.bases.size(); i++) {
		if (!p.bases[i].isAssigned()) {
			os << p.bases[i];
		}
	}
	return os;
}

Planet::Planet(string name) {
	this->name = name;
}

int Planet::searchBase(string name) const {
	for (unsigned i = 0; i < bases.size(); i++) {
		if (bases[i].getName() == name) {
			return i;
		}
	}
	return -1;
}

int Planet::searchShip(string name) const {
	for (unsigned i = 0; i < ships.size(); i++) {
		if (ships[i].getName() == name) {
			return i;
		}
	}
	return -1;
}

//True == base; False == ship
int Planet::askPeople(bool opt) {
	int input;
	if (opt) {
		cout << "Enter base people: ";
		cin >> input;
	}
	else {
		cout << "Enter ship maximum people: ";
		cin >> input;
	}
	return input;
}

int Planet::askEquipment(bool opt) {
	int input;
	if (opt) {
		cout << "Enter base equipment (Kg): ";
		cin >> input;
	}
	else {
		cout << "Enter ship maximum equipment: ";
		cin >> input;
	}
	return input;
}

Coordinate Planet::askCoordinates() {
	Coordinate c;
	cout << "Enter base coordinate: ";
	cin >> c;
	return c;
}

void Planet::modifyBase(int basePos) {
	char modifyOpt;
	cout << "Which base data (p/e/c)? ";
	cin >> modifyOpt;
	cin.get();
	switch (modifyOpt) {
	case 'p': {
		try {
			bases[basePos].setPeople(askPeople(true));
		}
		catch (Error error) {
			Util::error(error);
		}
	}
			  break;
	case 'e': {
		try {
			bases[basePos].setEquipment(askEquipment(true));
		}
		catch (Error error) {
			Util::error(error);
		}
	}
			  break;
	case 'c': {
		bases[basePos].setPosition(askCoordinates());
		break;
	}
	default:
		Util::error(ERR_UNKNOWN_OPTION);
		break;
	}
}

void Planet::createBase(string name) {
	if (name == "") {
		cout << "Enter base name: ";
		getline(cin, name);
	}
	int basePos = searchBase(name);
	if (basePos != -1) {
		cout << bases[basePos];
		char modifyOpt;
		cout << "Modify base data (Y/N)? ";
		cin >> modifyOpt;
		cin.get();
		if (modifyOpt == 'Y') {
			modifyBase(basePos);
		}
	}
	else {
		int people = askPeople(true);
		try {
			Base b(name, askCoordinates(), people, askEquipment(true));
			bases.push_back(b);
		}
		catch (Error error) {
			Util::error(error);
		}
	}
}

void Planet::createShip() {
	string name;
	cout << "Enter ship name: ";
	getline(cin, name);
	if (searchShip(name) == -1) {
		try {
			int people = askPeople(false);
			Ship s(name, people, askEquipment(false));
			ships.push_back(s);
		}
		catch (Error error) {
			Util::error(error);
		}
	}
	else {
		Util::error(ERR_WRONG_SHIP_NAME);
	}
}

void Planet::deleteBase(string name) {
	if (bases.size() == 0) {
		Util::error(ERR_NO_BASES);
	}
	else {
		if (name == "") {
			cout << "Enter base name: ";
			getline(cin, name);
		}
		int basePos = searchBase(name);
		if (basePos != -1) {
			char opt;
			cout << bases[basePos];
			cout << "Delete (Y/N)? ";
			cin >> opt;
			cin.get();
			if (opt == 'Y') {
				bases.erase(bases.begin() + basePos);
			}
		}
		else {
			Util::error(ERR_WRONG_BASE_NAME);
		}
	}
}

void Planet::deleteShip(string name) {
	if (ships.size() == 0) {
		Util::error(ERR_NO_SHIPS);
	}
	else {
		if (name == "") {
			cout << "Enter ship name: ";
			getline(cin, name);
		}
		int shipPos = searchShip(name);
		if (shipPos != -1) {
			char opt;
			cout << ships[shipPos];
			cout << "Delete (Y/N)? ";
			cin >> opt;
			cin.get();
			if (opt == 'Y') {
				ships.erase(ships.begin() + shipPos);
			}
		}
		else {
			Util::error(ERR_WRONG_SHIP_NAME);
		}
	}
}

//Finds the largest ship, without assigned bases, and returns its position in the vector.
int Planet::findLargestFreeShip() const {
	int largestIndex = -1;
	int largestSize = 0;
	for (unsigned i = 0; i < ships.size(); i++) {
		if (ships[i].getMaxPeople() > largestSize && !ships[i].hasBases()) {
			largestIndex = i;
			largestSize = ships[i].getMaxPeople();
		}
	}
	return largestIndex;
}

//Finds largest base that fits in a given ship, and returns its position in the vector.
int Planet::findLargestAvaliableBase(int shipIndex) const {
	int largestIndex = -1;
	int largestSize = 0;
	for (unsigned i = 0; i < bases.size(); i++) {
		if (ships[shipIndex].admitsBase(bases[i]) &&
			bases[i].getPeople() > largestSize) {
			largestIndex = i;
			largestSize = bases[i].getPeople();
		}
	}
	return largestIndex;
}

/*
* Finds the closest available base to the centroid of all the available bases
* and returns its position in the vector.
*/
int Planet::closestBaseToCentroid(Ship ship) const {
	int closestIndex = -1;
	double closestDistance;
	bool first = true;
	Coordinate centroid(ship.centroid());
	for (unsigned i = 0; i < bases.size(); i++) {
		if (ship.admitsBase(bases[i])) {
			double ed = centroid.distance(bases[i].getPosition());
			//cout << i << ": " << ed << endl;
			if (first || ed < closestDistance) {
				closestIndex = i;
				closestDistance = ed;
				first = false;
			}
		}
	}
	return closestIndex;
}

/*
* Once the largest base has been assigned to the largest ship, continue
* assigning the rest of the bases, by closeness to centroid.
*/
void Planet::assignRemainingBases(int shipIndex) {
	bool availableBases = true;
	while (availableBases) {
		int closestBase = closestBaseToCentroid(ships[shipIndex]);
		if (closestBase != -1) {
			Base* pBase = &bases[closestBase];
			ships[shipIndex].addBase(pBase);
		}
		else {
			availableBases = false;
		}
	}
}

//Main module of the evacuation plan
void Planet::evacuationPlan()
{
	if (ships.size() != 0) {
		int largestShip;
		do {
			largestShip = findLargestFreeShip();
			if (largestShip != -1) {
				cout << "Chosen ship: ";
				cout << ships[largestShip];
				int largestBase = findLargestAvaliableBase(largestShip);
				if (largestBase != -1) {
					Base* pBase = &bases[largestBase];
					ships[largestShip].addBase(pBase);
					assignRemainingBases(largestShip);
					cout << *this;
				}
				else {
					largestShip = -1;
				}
			}
		} while (largestShip != -1);
		for (unsigned i = 0; i < ships.size(); i++) {
			ships[i].detachBases();
		}
	}
}
