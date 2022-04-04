#include "utils.h"

vector<string> split(string s, char delim)
{
    vector<string> result;
    stringstream streamName(s);
    string item;

    while (getline(streamName, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

int isPass(Grades grade)
{
    if (grade == A || grade == A_plus || grade == A_minus || grade == B || grade == B_plus || grade == B_minus || grade == C || grade == C_plus || grade == C_minus || grade == D)
    {
        return 1;
    }
    else if (grade == F)
    {
        return 0;
    }
    return 2;
}

map<Grades, int> dataGrade(int courseno, vector<dataPerCourse> &data)
{
    map<Grades, int> courseMap;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].courseno == courseno)
        {
            if (data[i].grade == A)
            {
                courseMap[A]++;
            }
            else if (data[i].grade == A_plus)
            {
                courseMap[A_plus]++;
            }
            else if (data[i].grade == A_minus)
            {
                courseMap[A_minus]++;
            }
            else if (data[i].grade == B_minus)
            {
                courseMap[B_minus]++;
            }
            else if (data[i].grade == B_plus)
            {
                courseMap[B_plus]++;
            }
            else if (data[i].grade == B)
            {
                courseMap[B]++;
            }
            else if (data[i].grade == C_minus)
            {
                courseMap[C_minus]++;
            }
            else if (data[i].grade == C_plus)
            {
                courseMap[C_plus]++;
            }
            else if (data[i].grade == C)
            {
                courseMap[C]++;
            }
            else if (data[i].grade == W)
            {
                courseMap[W]++;
            }
            else if (data[i].grade == F)
            {
                courseMap[F]++;
            }
        }
    }
    return courseMap;
}

string fallOrSpring(string termId)
{
    if (termId == "T04" || termId == "T08" || termId == "T12" || termId == "T16" || termId == "T20" || termId == "T23")
    {
        return "Fall";
    }
    else if (termId == "T02" || termId == "T06" || termId == "T10" || termId == "T18" || termId == "T21")
    {
        return "Spring";
    }
    return termId;
}

Grades getEnumIndex(string grade)
{
    static map<string, Grades> string2Grade{
        {"A", A},
        {"A+", A_plus},
        {"A-", A_minus},
        {"AUD", AUD},
        {"B", B},
        {"B+", B_plus},
        {"B-", B_minus},
        {"C", C},
        {"C+", C_plus},
        {"C-", C_minus},
        {"CR", CR},
        {"D", D},
        {"D+", D_plus},
        {"D-", D_minus},
        {"F", F},
        {"FIN", FIN},
        {"INC", INC},
        {"NC", NC},
        {"P", P},
        {"W", W},
        {"WD", WD},
        {"WN", WN},
        {"WU", WU}};
    auto x = string2Grade.find(grade);
    return x->second;
}

void printData(vector<dataPerCourse> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i].emplid << " " << data[i].courseno << " " << data[i].instructorid
             << " " << data[i].termid << " " << data[i].sectionid << " " << data[i].grade << " " << endl;
    }
}

string IntToString(int number)
{
    stringstream temp;
    temp << number;
    return temp.str();
}

bool checkStudent(string id,vector<dataPerCourse> &data){
    for(int i = 0; i < data.size(); i++){
        if(data[i].emplid == id){
            return true;
        }
    }
    return false;
}

bool checkCourse(int id){
    if (id == 1115 || id == 3115 || id == 3130){
        return true;
    }
    return false;
}

bool checkInstructor(string id,vector<dataPerCourse> &data){
    for(int i = 0; i < data.size(); i++){
        if(data[i].instructorid == id){
            return true;
        }
    }
    return false;
}