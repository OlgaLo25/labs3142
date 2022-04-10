#ifndef WRITE_READ_H
#define WRITE_READ_H
#include "structures.h"
#include "utils.h"
#include <vector>
#include <fstream>

// void write(vector<Student> &students);
// void write(Student &student);
// vector<Student> read();
void writeData(vector<dataPerCourse> &data);
void write(string result);
void readUpdated(vector<dataPerCourse> &data,char delimeter,string filename);
vector<dataPerCourse> readCSV();

#endif