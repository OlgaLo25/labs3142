#include "postfix.h"
using namespace std;

int Postfix::priorityLexem(Lexem lex)
{
    if (lex.op == lex.ADD || lex.op == lex.SUBSTRACT)
    {
        return 1;
    }
    else if (lex.op == lex.MULTIPLY || lex.op == lex.DIVIDE)
    {
        return 2;
    }
    else if (lex.op == lex.SQRT || lex.op == lex.POW)
    {
        return 3;
    }

    return 0;
}

int Postfix::priorityLine(string operand)
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

    return 0;
}

vector<Lexem> Postfix::getResultStack(vector<string> line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if (!isOperandLine(line[i]))
        {
            // push //top //pop
            stringstream ss;
            double number;
            ss << line[i];
            ss >> number;
            Lexem lex{Lexem::NUMBER, number};
            result.push_back(lex);
        }
        else
        {
            Lexem lex;
            string type = line[i];
            if(type=="("){
                lex.op = Lexem::OPEN_BRACKET;
            }
            else if(type == "+"){
                lex.op = Lexem::ADD;
            }
            else if(type == "-"){
                lex.op = Lexem::SUBSTRACT;
            }
            else if(type == "*"){
                lex.op = Lexem::MULTIPLY;
            }
            else if(type == "/"){
                lex.op = Lexem::DIVIDE;
            }
            else if(type == "^"){
                lex.op = Lexem::POW;
            }
            else if(type == "sqrt"){
                lex.op = Lexem::SQRT;
            }

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
                    if (priorityLexem(operators.top()) < priorityLine(type))
                    {
                        operators.push(lex);
                    }
                    else
                    {   
                        while (!operators.empty() && (priorityLexem(operators.top()) >= priorityLine(type)))
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
                    while (operators.top().op!= Lexem::OPEN_BRACKET)
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
