#ifndef POSTFIX_H
#define POSTFIX_H
#include <vector>
#include <string>
#include <stack>
#include "structure.h"
#include <sstream>
#include "utils.h"
using namespace std;


class Postfix
{

private:
    vector<Lexem> result;
    stack<Lexem> operators;
    int priorityLine(string operand);
    int priorityLexem(Lexem lex);
public:
    vector<Lexem> getResultStack(vector<string> line);
};
#endif