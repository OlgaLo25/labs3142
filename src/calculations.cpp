#include "calculations.h"

Calculation::Calculation(vector<dataPerCourse> &data)
{
    this->data = data;
}

void Calculation::max()
{
    map<Grades, int> map1115 = dataGrade(1115, data);
    map<Grades, int> map3115 = dataGrade(3115, data);
    map<Grades, int> map3130 = dataGrade(3130, data);

    int array[3] = {map1115[A], map3115[A], map3130[A]};
    int max = array[0];
    int indexOfMap = 0;
    string courseMaxGrade = "1115";
    for (int i = 1; i < 3; i++)
    {

        if (array[i] > max)
        {
            max = array[i];
            indexOfMap = i;
        }
    }

    if (indexOfMap == 1)
    {
        courseMaxGrade = "3115";
    }
    else
    {
        courseMaxGrade = "3130";
    }

    cout << "The maximum quantity of A grade is: " << max << " on the " << courseMaxGrade << " course" << endl;
    string result = "The maximum quantity of A grade is: " + IntToString(max) + " on the " + courseMaxGrade + " course\n";
    write(result + "\n");
}

void Calculation::count()
{
    int sum1115 = 0;
    int sum3115 = 0;
    int sum3130 = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].courseno == 1115)
        {
            sum1115++;
        }
        else if (data[i].courseno == 3115)
        {
            sum3115++;
        }
        else if (data[i].courseno == 3130)
        {
            sum3130++;
        }
    }
    cout << "The quantity of students enrolled to course CISC 1115 is: " << sum1115 << endl;
    cout << "The quantity of students enrolled to course CISC 3115 is: " << sum3115 << endl;
    cout << "The quantity of students enrolled to course CISC 3130 is: " << sum3130 << endl;

    string result = "The quantity of students enrolled to course CISC 1115 is: " + IntToString(sum1115) + "\n" + "The quantity of students enrolled to course CISC 3115 is: " + IntToString(sum3115) + "\n" + "The quantity of students enrolled to course CISC 3130 is: " + IntToString(sum3130) + "\n";
    write(result + "\n");
}

void Calculation::passRate()
{

    set<string> instructorList = getInstructors();
    set<string>::iterator itrInstructor;

    for (itrInstructor = instructorList.begin(); itrInstructor != instructorList.end(); itrInstructor++)
    {
        instructorPassRate(*itrInstructor);
    }
    printf("\n");
    write("\n");

    set<int> courseList = getCourseNo();
    set<int>::iterator itrCourse;

    for (itrCourse = courseList.begin(); itrCourse != courseList.end(); itrCourse++)
    {
        coursePassRate(*itrCourse);
    }
    printf("\n");
    write("\n");

    set<string> termList = getTermNo();
    set<string>::iterator itrTerm;

    for (itrTerm = termList.begin(); itrTerm != termList.end(); itrTerm++)
    {
        termPassRate(*itrTerm);
    }
    write("\n");
}

void Calculation::wInstructorRate(string instructorId)
{
    if (checkInstructor(instructorId,data))
    {
        int wQuantity = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (instructorId == data[i].instructorid && data[i].grade == W)
            {
                wQuantity++;
            }
        }

        printf("For instructor Id - %s  the quantity of students with \"W\" - %d\n", instructorId.c_str(), wQuantity);
        string result = "For instructor Id - " + instructorId + "  the quantity of students with \"W\" - " + IntToString(wQuantity) + "\n";
    }
    else
    {
        printf("No such instructor\n");
    }
}

void Calculation::wCourseRate(int courseNo)
{
    if (checkCourse(courseNo))
    {
        int wQuantity = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (courseNo == data[i].courseno && data[i].grade == W)
            {
                wQuantity++;
            }
        }

        printf("For course number - %d  the quantity of students with \"W\" - %d\n", courseNo, wQuantity);
        string result = "For instructor Id - " + IntToString(courseNo) + "  the quantity of students with \"W\" - " + IntToString(wQuantity) + "\n";
    }
    else{
        printf("No such course\n");
        write("No such course\n");
    }
}

set<string> Calculation::getInstructors()
{
    set<string> instructorsList;
    for (int i = 0; i < data.size(); i++)
    {
        instructorsList.insert(data[i].instructorid);
    }
    return instructorsList;
}

void Calculation::instructorPassRate(string instructorId)
{
    int studentsPass = 0;
    int studentsFail = 0;
    int studentsUnknown = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].instructorid == instructorId)
        {

            if (isPass(data[i].grade) == 1)
            {
                studentsPass++;
            }
            else if (isPass(data[i].grade) == 0)
            {
                studentsFail++;
            }
            else
            {
                studentsUnknown++;
            }
        }
    }

    printf("Instructor id - %s\t The quantity of students pass - %d\t The quantity of students fail - %d\t Other students - %d\n",
           instructorId.c_str(), studentsPass, studentsFail, studentsUnknown);

    string result = "Instructor id - " + instructorId + "\t The quantity of students pass - " + IntToString(studentsPass) + "\t The quantity of students fail - " + IntToString(studentsFail) + "\t Other students - " + IntToString(studentsUnknown) + "\n";
    write(result);
}

set<int> Calculation::getCourseNo()
{
    set<int> courseList;
    for (int i = 0; i < data.size(); i++)
    {
        courseList.insert(data[i].courseno);
    }
    return courseList;
}

void Calculation::coursePassRate(int courseNo)
{
    int studentsPass = 0;
    int studentsFail = 0;
    int studentsUnknown = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].courseno == courseNo)
        {
            if (isPass(data[i].grade) == 1)
            {
                studentsPass++;
            }
            else if (isPass(data[i].grade) == 0)
            {
                studentsFail++;
            }
            else
            {
                studentsUnknown++;
            }
        }
    }

    printf("Course Number - %d\t The quantity of students pass - %d\t The quantity of students fail - %d\t Other students - %d\n",
           courseNo, studentsPass, studentsFail, studentsUnknown);

    string result = "Course Number - " + IntToString(courseNo) + "\t The quantity of students pass - " + IntToString(studentsPass) + "\t The quantity of students fail - " + IntToString(studentsFail) + "\t Other students - " + IntToString(studentsUnknown) + "\n";
    write(result);
}

set<string> Calculation::getTermNo()
{
    set<string> termList;
    for (int i = 0; i < data.size(); i++)
    {
        termList.insert(data[i].termid);
    }
    return termList;
}

void Calculation::termPassRate(string termId)
{
    int studentsPass = 0;
    int studentsFail = 0;
    int studentsUnknown = 0;
    string fallSpring = fallOrSpring(termId);
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].termid == termId)
        {
            if (isPass(data[i].grade) == 1)
            {
                studentsPass++;
            }
            else if (isPass(data[i].grade) == 0)
            {
                studentsFail++;
            }
            else
            {
                studentsUnknown++;
            }
        }
    }

    printf("Term Id - %s\t The quantity of students pass in %s - %d\t The quantity of students fail - %d\t Other students - %d\n",
           termId.c_str(), fallSpring.c_str(), studentsPass, studentsFail, studentsUnknown);

    string result = "Term Id - " + termId + "\t The quantity of students pass in " + fallSpring + " - " + IntToString(studentsPass) +
                    "\t The quantity of students fail - " + IntToString(studentsFail) + "\t Other students - " + IntToString(studentsUnknown) + "\n";
    write(result);
}
