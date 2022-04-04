#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "write_read.h"
#include "utils.h"


class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testInstructor);
  CPPUNIT_TEST(testStudent);
  CPPUNIT_TEST(testCourse);
  CPPUNIT_TEST_SUITE_END();
private:
vector<dataPerCourse> data;
public:
  void setUp(void) {
      data = readCSV();
  }
  void tearDown(void) {}

protected:

  void testInstructor(void) {
    CPPUNIT_ASSERT(checkInstructor("I28",data)==true);
  }

  void testStudent(void) {
    CPPUNIT_ASSERT(checkStudent("not exist id",data)==false);
  }

  void testCourse(void) {
    CPPUNIT_ASSERT(checkCourse(3130)==true);
  }

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()

{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}