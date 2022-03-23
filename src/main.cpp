#include <string>
#include <iostream>
#include <vector>
#include "utils.h"
#include "postfix.h"
#include "calculation.h"

using namespace std;
int main()
{
    printf("Enter the expression\n");
    string input;
    cin >> input;
    vector<string> resultLine = splitLine(input);
    if (checkTwoSigns(resultLine)==true)
    {
        Postfix postfixres;
        vector<Lexem> resultVector = postfixres.getResultStack(resultLine);
        Calculation calc;
        printf("The result is: %.3f\n", calc.getCalculation(resultVector));
    }
    else{
        printf("Incorrect expression\n");
    }
};
