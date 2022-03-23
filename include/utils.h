#ifndef UTILS_H
#define UTILS_H
#include "structure.h"
#include <vector>
#include <string>

using namespace std;

bool checkTwoSigns(vector<string> input);
bool isOperandLine(string type);
bool isOperand(Lexem lex);
vector<string> splitLine(string input);
vector<string> split(string line,char delimeter);

#endif
