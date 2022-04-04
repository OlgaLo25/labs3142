#ifndef CALCULATION_H
#define CALCULATION_H
#include "structures.h"
#include "utils.h"
#include "write_read.h"
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

// W rate per instructor (and per course number) -done



class Calculation
{
private:
    vector<dataPerCourse> data;

    set<string> getInstructors();
    void instructorPassRate(string instructorId);

    set<int> getCourseNo();
    void coursePassRate(int courseNo);

    set<string> getTermNo();
    void termPassRate(string termNo);

public:
    Calculation(vector<dataPerCourse> &data);
    void count();
    void max();
    void passRate();
    void wInstructorRate(string instructorId);
    void wCourseRate(int courseNo);
};
#endif