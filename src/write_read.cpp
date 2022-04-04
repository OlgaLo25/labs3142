#include "write_read.h"

// void write(vector<Student> &students)
// {
//     ofstream out("output.txt");

//     if (out.is_open())
//     {
//         for (int i = 0; i < students.size(); i++)
//         {
//             out << students[i].id << " " << students[i].course.id << " " << students[i].course.courseNumber << " " << students[i].course.sectionCode
//                 << " " << students[i].course.term.id
//                 << " " << students[i].course.term.name << " " << students[i].grade;
//         }

//         out.close();
//     }
// }


// vector<Student> read()
// {
//     vector<Student> students;
//     ifstream in("output.txt");
//     if (in.is_open())
//     {
//         string line;
//         bool skipFirstLine = true;
//         while (getline(in, line))
//         {
//             if (skipFirstLine)
//             {
//                 skipFirstLine = false;
//                 continue;
//             }
//             vector<string> lineSplit = split(line, ',');
//             int studentId;
//             stringToSomething<string, int>(lineSplit.at(0), studentId);

//             int courseId;
//             stringToSomething<string, int>(lineSplit.at(1), courseId);

//             int courseNumber;
//             stringToSomething<string, int>(lineSplit.at(2), courseNumber);

//             string sectionCode = lineSplit.at(3);

//             int termId;
//             stringToSomething<string, int>(lineSplit.at(4), termId);

//             string termName = lineSplit.at(5);

//             char grade;
//             stringToSomething<string, char>(lineSplit.at(6), grade);

//             Term term{termId, termName};
//             Course course{courseId, courseNumber, sectionCode, term};
//             Student student{studentId, course, grade};

//             students.push_back(student);
//         }
//     }

//     return students;
// }

vector<dataPerCourse> readCSV()
{
    vector<dataPerCourse> data;

    string files[3] = {"../data/1115.csv", "../data/3115.csv", "../data/3130.csv"};

    for (int i = 0; i < 3; i++)
    {
        ifstream in(files[i]);
        if (in.is_open())
        {
            string line;
            bool skipFirstLine = true;
            while (getline(in, line))
            {
                if (skipFirstLine)
                {
                    skipFirstLine = false;
                    continue;
                }
                vector<string> lineSplit = split(line, ',');
                string emplid = lineSplit[0];

                int courseno;
                stringToSomething<string, int>(lineSplit.at(1), courseno);

                string instructorid = lineSplit[2];
                string termid = lineSplit[3];
                string sectionid = lineSplit[4];
                string grade = lineSplit[5];
                

                dataPerCourse row{emplid, courseno, instructorid, termid, sectionid, getEnumIndex(grade)};
                data.push_back(row);
            }
        }
    }
    return data;
}

void write(string result)
{
    ofstream out("output.txt", ios::app);

    if (out.is_open())
    {
        out << result;
        out.close();
    }
    
}
