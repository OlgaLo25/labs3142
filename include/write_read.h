#ifndef WRITE_READ_H
#define WRITE_READ_H
#include "structures.h"
#include "utils.h"
#include <vector>
#include <fstream>

// void write(vector<Student> &students);
// void write(Student &student);
// vector<Student> read();
vector<dataPerCourse> readCSV();
void write(string result);

#endif