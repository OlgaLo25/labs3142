#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include "utils.h"
#include "postfix.h"
#include "calculation.h"

class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testLab2);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void testLab2(void) {
    char inputExample[] = "1+2*3^3-7+(2-3)";
    printf("The expression is: %s\n",inputExample);

    vector<string> resultLine = splitLine("1+2*3^3-7+(2-3)");
    
    Postfix postfixres;
    vector<Lexem> resultVector = postfixres.getResultStack(resultLine);
    Calculation calc;
       
    CPPUNIT_ASSERT(calc.getCalculation(resultVector)==47.000);
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