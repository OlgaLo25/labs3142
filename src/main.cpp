#include <string>
#include <iostream>
#include <vector>
#include "utils.h"
#include "postfix.h"
#include "calculation.h"

int main()
{
    printf("Enter the expression\n");
    string input(100, '\0');
    scanf("%s", input.c_str());
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
