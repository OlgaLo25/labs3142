#ifndef STRUCTURES_H
#define STRUCTURES_H
using namespace std;
#include <string>
// Student (ID, Course, Grade)
// Instructor (ID, Course, Term)
// Term (ID, Display Name)
// Course (ID, CourseNumber, SectionCode, Term)

// A, A+, A-, AUD, B, B+, B-, C, C+, C-, CR, D, D+, D-, F, FIN, INC, NC, P, W, WD, WN, WU
 enum Grades
    {
        A,A_plus,A_minus,AUD,
        B,B_plus,B_minus,
        C,C_plus,C_minus,CR,
        D,D_plus,D_minus,
        F,FIN,
        INC,NC,
        P,
        W,WD,WN,WU
    };

struct dataPerCourse
{
    string emplid;
    int courseno;
    string instructorid;
    string termid;
    string sectionid;
    Grades grade;
};

// struct Term
// {
//     int id;
//     string name;
// };

// struct Course
// {
//     int id;
//     int courseNumber;
//     string sectionCode;
//     Term term;
// };

// struct Student
// {
//     string id;
//     Course course;
//     string grade;
// };

// struct Instructor
// {
//     string id;
//     Course course;
//     Term term;
// };

#endif