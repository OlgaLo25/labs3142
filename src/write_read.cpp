#include "write_read.h"

void writeData(vector<dataPerCourse> &data)
{
    ofstream out("outputUpdated.txt");
    char *enumStrings[] = {"A", "A+", "A-", "AUD", "B", "B+", "B-", "C", "C+", "C-", "CR", "D", "D+", "D-", "F", "FIN", "INC", "NC", "P", "W", "WD", "WN", "WU"};
    if (out.is_open())
    {
        for (int i = 0; i < data.size(); i++)
        {
            out << data[i].emplid << " " << data[i].courseno << " " << data[i].instructorid << " " << data[i].termid
                << " " << data[i].sectionid
                << " " << enumStrings[data[i].grade] << endl;
        }

        out.close();
    }
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

void readUpdated(vector<dataPerCourse> &data, char delimeter, string filename)
{
    ifstream in(filename);
    if (in.is_open())
    {
        string line;
        bool skipFirstLine = true;
        while (getline(in, line))
        {
            if (skipFirstLine && delimeter == ',')
            {
                skipFirstLine = false;
                continue;
            }
            vector<string> lineSplit = split(line, delimeter);
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
    in.close();
}

vector<dataPerCourse> readCSV()
{
    vector<dataPerCourse> data;

    string outputFile = "../output/outputUpdated.txt";
    int length = 3;
    string files[length] = {"../data/1115.csv", "../data/3115.csv", "../data/3130.csv"};

    ifstream in;
    in.open(outputFile);
    if (in)
    {
        readUpdated(data, ' ', outputFile);
    }
    else
    {
        for(int i = 0;i<length;i++){
            readUpdated(data, ',', files[i]);
        }
    }
    in.close();
    return data;
}
