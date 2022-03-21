#include <string>
#include <iostream>
#include <vector>
#include "utils.h"
#include "postfix.h"
#include "calculation.h"

using namespace std;
int main()
{
    string input = "10+5*2-(3*sqrt(4))";
    // printf("Please enter the expression\n");
    // cin >> input;
    vector<string> resultLine = splitLine(input);
    
    Postfix postfixres;
    vector<Lexem> resultVector = postfixres.getResultStack(resultLine);
    Calculation calc;
   
    printf("The result is: %.3f", calc.getCalculation(resultVector));
    

    // 2 * 3 + ( 3 - sqrt ( 4 ) )
    return 0;
};
