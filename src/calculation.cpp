#include "calculation.h"

//1+2^3

//123^+
double Calculation::getCalculation(vector<Lexem> resultVector)
{
    double result;

    for (int i = 0; i < resultVector.size(); i++)
    {
        if (isOperand(resultVector[i].type))
        {
            if (resultVector[i].type != "sqrt")
            {
                if (resultVector[i].type == "+")
                {
                    result = resultVector[i - 2].value + resultVector[i - 1].value;
                }
                else if (resultVector[i].type == "-")
                {
                    result = resultVector[i - 2].value - resultVector[i - 1].value;
                }
                else if (resultVector[i].type == "*")
                {
                    result = resultVector[i - 2].value * resultVector[i - 1].value;
                }
                else if (resultVector[i].type == "/")
                {
                    result = resultVector[i - 2].value / resultVector[i - 1].value;
                }
                else if (resultVector[i].type == "^")
                {
                    result = pow(resultVector[i - 2].value, resultVector[i - 1].value);
                }
                resultVector.erase(resultVector.begin()+i);
                resultVector.erase(resultVector.begin()+i-1);
                resultVector.erase(resultVector.begin()+i-2);
                
                i = i-2;
                Lexem lexInserted{"0",result};

                resultVector.insert(resultVector.begin()+i,lexInserted);
            }
            else
            {
                result = sqrt(resultVector[i - 1].value);
                resultVector.erase(resultVector.begin()+i);
                resultVector.erase(resultVector.begin()+i-1);
                i = i-1;
                Lexem lexInserted{"0",result};

                resultVector.insert(resultVector.begin()+i,lexInserted);
            }
        }
    }

    return resultVector[0].value;
}