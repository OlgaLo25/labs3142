#include "controller.h"

Controller::Controller(vector<dataPerCourse> &data)
{
    this->data = data;
}

void Controller::searchStudent(string emplId)
{
    if (checkStudent(emplId,data))
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
    else{
        printf("No such student");
        write("No such student");
    }
}

void Controller::enroll()
{
    // int studentId;
    // int courseId;
    // int courseNumber;
    // string sectionCode;
    // int termId;
    // string termName;
    // char grade;

    // cout<<"Enter the student's ID "<<endl;
    // cin>>studentId;
    // cout<<"Enter the course ID "<<endl;
    // cin>>courseId;
    // cout<<"Enter the course number "<<endl;
    // cin>>courseNumber;
    // cout<<"Enter the course section code "<<endl;
    // cin>>sectionCode;
    // cout<<"Enter the course term ID "<<endl;
    // cin>>termId;
    // cout<<"Enter the course term name "<<endl;
    // cin>>termName;
    // cout<<"Enter the student`s grade "<<endl;
    // cin>>grade;

    // Term term{termId,termName};
    // Course course{courseId,courseNumber,sectionCode,term};
    // Student student{studentId,course,grade};

    // write(student); //IP
}

void Controller::update()
{
    // int studentId;
    // char newGrade;
    // cout<<"Enter the id of student to change the grade"<<endl;
    // cin>>studentId;
    // cout<<"Enter updated grade"<<endl;
    // cin>>newGrade;

    // vector<Student> students = read();
    // vector<Student>::iterator it = students.begin();//указатель на элемент вектора
    // for(it; it!=students.end(); it++){
    //     if(studentId==it->id){
    //         it->grade=newGrade;
    //     }
    // }

    // write(students);
}