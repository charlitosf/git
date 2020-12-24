#include <cxxtest/TestSuite.h>

#include <iostream>
using namespace std;

#include "../src/Coordinate.h"

class TestSuiteAC : public CxxTest::TestSuite {

public:

  // Tests for Coordinate ---------------------------------------------

  void testCoordinate() {
    // Constructor
    const Coordinate c1(3.14,2.14);
    TS_ASSERT_EQUALS(c1.getX(),3.14);
    TS_ASSERT_EQUALS(c1.getY(),2.14);
    
    // Empty constructor
    Coordinate c2;
    
    // Output operator
    Coordinate c3(-3.1,-3.1);
    stringstream ss;
    ss<<c3;
    string s;
    ss>>s;
    TS_ASSERT_EQUALS(s,"(-3.1,-3.1)");
    
    // Input operator
    istringstream ss2("-2.1 -3.23");
    Coordinate c4;
    ss2>>c4;
    TS_ASSERT_EQUALS(c4.getX(),-2.1);
    TS_ASSERT_EQUALS(c4.getY(),-3.23);

    // Distance
    double d = c4.distance(c1);
    TS_ASSERT_DELTA(d,7.5029,0.01);
    
  }
};
