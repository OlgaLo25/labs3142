#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string>
using namespace std;

struct Lexem
{
    string type;//для числа тип = 0 ; "+" , "-"
    double value; // есть значение для числа; для операций =0
};
#endif