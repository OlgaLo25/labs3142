#include "postfix.h"
#include <iostream>
using namespace std;
int Postfix::priority(string operand)
{
    if (operand == "+" || operand == "-")
    {
        return 1;
    }
    else if (operand == "*" || operand == "/")
    {
        return 2;
    }
    else if (operand == "sqrt" || operand == "^")
    {
        return 3;
    }
    // Add sqrt and pow
    return 0;
}

vector<Lexem> Postfix::getResultStack(vector<string> line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if (!isOperand(line[i]))
        {
            // push //top //pop
            stringstream ss;
            double number;
            ss << line[i];
            ss >> number;
            Lexem lex{"0", number};
            result.push_back(lex);
        }
        else
        {
            string type = line[i];
            Lexem lex{type, 0};

            if (operators.empty())
            {
                operators.push(lex);
            }

            else
            {
                if (line[i] == "(")
                {
                    operators.push(lex);
                }
                else if (line[i] != ")")
                {
                    if (priority(operators.top().type) < priority(type))
                    {
                        operators.push(lex);
                    }
                    else
                    {   
                        while (!operators.empty() && (priority(operators.top().type) >= priority(type)))
                        {
                            Lexem topLex = operators.top();
                            result.push_back(topLex);
                            operators.pop();
                        }
                        operators.push(lex);
                    }
                }
                else
                {
                    while (operators.top().type != "(")
                    {
                        Lexem topLex = operators.top();
                        result.push_back(topLex);
                        operators.pop();
                    }
                    operators.pop();
                }
            }
        }
    }

    while (!operators.empty())
    {
        Lexem topLex = operators.top();
        result.push_back(topLex);
        operators.pop();
    }

    return result;
}

// 1+2*sqrt(4)+2^3
