#include "utils.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool isOperand(string part)
{

    if (part == "+" || part == "-" || part == "/" || part == "*" || part == "(" || part == ")" || part == "sqrt" || part == "^")
    {
        return true;
    }

    return false;
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
    return split(result, ' ');
}

vector<string> split(string s, char delim)
{
    vector<string> result;
    stringstream streamName(s);
    string item;

    while (getline(streamName, item, delim))
    {
        result.push_back(item);
    }

    return result;
}