#include "Util.h"

void Util::error(Error n)
{
  switch (n) {

    case ERR_UNKNOWN_OPTION:
      cout << "Error, unknown option" << endl;
      break;

    case ERR_WRONG_NUMBER:
      cout << "Error, wrong number, must be positive" << endl;
      break;

    case ERR_LOW_PEOPLE:
      cout << "Error, low people number" << endl;
      break;

    case ERR_WRONG_BASE_NAME:
      cout << "Error, base name not found" << endl;
      break;

    case ERR_WRONG_SHIP_NAME:
      cout << "Error, wrong ship name" << endl;
      break;

    case ERR_NO_BASES:
      cout << "Error, there are no bases in the planet" << endl;
      break;

    case ERR_NO_SHIPS:
      cout << "Error, there are no ships in the planet" << endl;
      break;
  }
}
