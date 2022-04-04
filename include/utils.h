#ifndef UTILS_H
#define UTILS_H
#include "structures.h"
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

//Common functions
vector<string> split(string s, char delim);

int isPass(Grades grade);

map<Grades, int> dataGrade(int courseno,vector<dataPerCourse> &data);

string fallOrSpring(string termId);

Grades getEnumIndex( string grade);

void printData(vector<dataPerCourse> &data);

string IntToString(int number);

bool checkStudent(string id,vector<dataPerCourse> &data);

bool checkCourse(int id);

bool checkInstructor(string id,vector<dataPerCourse> &data);
//Шаблонные функции всегда надо реализовывать в headers file
template <typename Text, typename TypeToConvert>
void stringToSomething(Text stringText, TypeToConvert &typeConvert)
{
    stringstream syear(stringText);
    syear >> typeConvert;
}

#endif