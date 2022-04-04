#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "structures.h"
#include <vector>
#include <iostream>
#include "write_read.h"
#include "utils.h"

class Controller
{
private:
    vector<dataPerCourse> data;
    void enroll();

public:
    Controller(vector<dataPerCourse> &data);
    void update();
    void searchStudent(string emplId);
};
#endif
