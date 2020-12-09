#ifndef _UTIL_H_
#define _UTIL_H_
#include <iostream>
using namespace std;

enum Error {
  ERR_UNKNOWN_OPTION,
  ERR_WRONG_NUMBER,
  ERR_LOW_PEOPLE,
  ERR_WRONG_BASE_NAME,
  ERR_WRONG_SHIP_NAME,
  ERR_NO_BASES,
  ERR_NO_SHIPS
};

class Util{
public:
  static void error(Error n);
};
#endif
