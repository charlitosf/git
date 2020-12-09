/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "wn";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestSuiteAC_init = false;
#include "test.h"

static TestSuiteAC suite_TestSuiteAC;

static CxxTest::List Tests_TestSuiteAC = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestSuiteAC( "test.h", 8, "TestSuiteAC", suite_TestSuiteAC, Tests_TestSuiteAC );

static class TestDescription_suite_TestSuiteAC_testCoordinate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSuiteAC_testCoordinate() : CxxTest::RealTestDescription( Tests_TestSuiteAC, suiteDescription_TestSuiteAC, 14, "testCoordinate" ) {}
 void runTest() { suite_TestSuiteAC.testCoordinate(); }
} testDescription_suite_TestSuiteAC_testCoordinate;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
