#include "utils.h"
#include <string>
#include <sstream>
using namespace std;

bool isOperandLine(string type)
{

    if (type == "+" || type == "-" || type == "/" || type == "*" || type == "(" || type == ")" || type == "sqrt" || type == "^")
    {
        return true;
    }

    return false;
}

bool isOperand(Lexem lex)
{

    if (lex.op == lex.ADD || lex.op == lex.SUBSTRACT || lex.op == lex.DIVIDE || lex.op == lex.MULTIPLY || lex.op == lex.OPEN_BRACKET || lex.op == lex.SQRT || lex.op == lex.POW)
    {
        return true;
    }

    return false;
}

bool checkTwoSigns(vector<string> input){
    for(int i=0;i<input.size();i++){
        if(input[i]==""){
            return false;
        }
    }
    return true;
}

vector<string> splitLine(string input)
{
    string result;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] =='^')
        {
            result += ' ';
            result += input[i];
            result += ' ';
        }
        else if (input[i] == '(')
        {
            result += input[i];
            result += ' ';
        }
        else if (input[i] == ')')
        {
            result += ' ';
            result += input[i];
        }
        else if(input[i] =='t' && input[i-1] =='r' && input[i-2] =='q' && input[i-3] =='s'){
            result += input[i];
            result += ' ';
        }
        else
        {
            result += input[i];
        }
    }

    vector<string> resultVector = split(result, ' ');
 
    return resultVector;
}

vector<string> split(string line, char delim)
{
    vector<string> result;
    stringstream streamName(line);
    string item;

    while (getline(streamName, item, delim))
    {
        result.push_back(item);
    }

    return result;
}