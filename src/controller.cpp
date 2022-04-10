#include "controller.h"

Controller::Controller(vector<dataPerCourse> &data)
{
    this->data = data;
}

void Controller::searchStudent(string emplId)
{
    if (checkStudent(emplId, data))
    {
        dataPerCourse student;
        printf("The student's Id is %s\n", emplId.c_str());
        write("The student's Id is " + emplId + "\n");
        char *enumStrings[] = {"A", "A+", "A-", "AUD", "B", "B+", "B-", "C", "C+", "C-", "CR", "D", "D+", "D-", "F", "FIN", "INC", "NC", "P", "W", "WD", "WN", "WU"};

        for (int i = 0; i < data.size(); i++)
        {
            if (emplId == data[i].emplid)
            {
                student = data[i];

                printf("Course - %d; Instructor Id - %s; Term - %s; Section Id - %s; Grade - %s\n",
                       student.courseno, student.instructorid.c_str(),
                       student.termid.c_str(), student.sectionid.c_str(), enumStrings[student.grade]);
                string result = "Course - " + IntToString(student.courseno) + "; Instructor Id - " + student.instructorid + "; Term - " + student.termid + "; Section Id - " + student.sectionid + "; Grade - " + enumStrings[student.grade] + "\n";
                write(result);
            }
        }
    }
    else
    {
        printf("No such student");
        write("No such student");
    }
}

/*
A user-defined class with methods for enrollment operations
A constructor for define a new enrollment (i.e. it creates a student object with a new course). The enrollment should not be publicly accessible
Method(s) for updating objects (i.e. update grades for the student object(s))

*/
void Controller::enroll()
{

    string emplId;
    int courseno;
    string instructorId;
    string termId;
    string sectionId;
    string grade;

    cout << "Enter the student's ID " << endl;
    cin >> emplId;

    if (checkStudent(emplId, data) == false)
    {
        cout << "Enter the course number " << endl;
        cin >> courseno;
        cout << "Enter the instructor ID " << endl;
        cin >> instructorId;
        cout << "Enter the course term ID " << endl;
        cin >> termId;
        cout << "Enter the course section ID " << endl;
        cin >> sectionId;
        cout << "Enter the student`s grade " << endl;
        cin >> grade;
        Grades enumGrade = getEnumIndex(grade);
        dataPerCourse enrollData{emplId, courseno, instructorId, termId, sectionId, enumGrade};
        data.push_back(enrollData);
        writeData(data);
    }
    else
    {
        cout << "Student already exists" << endl;
    }
}

void Controller::update()
{
    string emplId;
    cout << "Enter student's ID to update the grade" << endl;
    cin >> emplId;

    if (checkStudent(emplId, data) == true)
    {
        cout << "Enter updated grade" << endl;
        string newGrade;
        cin >> newGrade;
        Grades grade = getEnumIndex(newGrade);

        vector<dataPerCourse>::iterator it = data.begin(); //указатель на элемент вектора
        for (it; it != data.end(); it++)
        {
            if (emplId == it->emplid)
            {
                it->grade = grade;
            }
        }
        writeData(data);
    }
    else{
        cout<<"Student doesnt exist"<<endl;
    }
}