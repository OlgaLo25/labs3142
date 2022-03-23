#include "calculation.h"

double Calculation::getCalculation(vector<Lexem> resultVector)
{
    double result;

    for (int i = 0; i < resultVector.size(); i++)
    {
        if (isOperand(resultVector[i]))
        {
            if (resultVector[i].op != resultVector[i].SQRT)
            {
                if (resultVector[i].op == resultVector[i].ADD)
                {
                    result = resultVector[i - 2].value + resultVector[i - 1].value;
                }
                else if (resultVector[i].op == resultVector[i].SUBSTRACT)
                {
                    result = resultVector[i - 2].value - resultVector[i - 1].value;
                }
                else if (resultVector[i].op == resultVector[i].MULTIPLY)
                {
                    result = resultVector[i - 2].value * resultVector[i - 1].value;
                }
                else if (resultVector[i].op == resultVector[i].DIVIDE)
                {
                    result = resultVector[i - 2].value / resultVector[i - 1].value;
                }
                else if (resultVector[i].op == resultVector[i].POW)
                {
                    result = pow(resultVector[i - 2].value, resultVector[i - 1].value);
                }
                resultVector.erase(resultVector.begin()+i);
                resultVector.erase(resultVector.begin()+i-1);
                resultVector.erase(resultVector.begin()+i-2);
                
                i = i-2;
                Lexem lexInserted{Lexem::NUMBER,result};

                resultVector.insert(resultVector.begin()+i,lexInserted);
            }
            else
            {
                result = sqrt(resultVector[i - 1].value);
                resultVector.erase(resultVector.begin()+i);
                resultVector.erase(resultVector.begin()+i-1);
                i = i-1;
                Lexem lexInserted{Lexem::NUMBER,result};

                resultVector.insert(resultVector.begin()+i,lexInserted);
            }
        }
    }

    return resultVector[0].value;
}