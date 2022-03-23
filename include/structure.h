#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string>
using namespace std;

struct Lexem
{
    enum {ADD, SUBSTRACT, MULTIPLY, DIVIDE, SQRT, POW, OPEN_BRACKET, NUMBER} op;
    // string type;//для числа тип = 0 ; "+" , "-"
    double value; // есть значение для числа; для операций =0
};
#endif