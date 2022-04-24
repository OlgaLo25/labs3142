#include "controller.h"
#include "write_read.h"
#include "calculations.h"
#include <chrono>
using namespace std::chrono;
// все записать в файл
// проверка на студента, курс, на инструктора
// тесты добавить

void commands()
{
    vector<dataPerCourse> data = readCSV();
    Calculation calc(data);
    Controller controller(data);

    cout << "Enter 1 - for maximum quantity of A grade students \nEnter 2 - for student`s quantity per course \n"
         << "Enter 3 - for pass rate \nEnter 4 - for instructor pass rate \nEnter 5 - for course pass rate \n"
         << "Enter 6 - search student \nEnter 7 - enroll student \nEnter 8 - update student info\nEnter 0 - for exit \n"
         << endl;

    string instructorId;
    int courseno;
    string studentId;
    while (true)
    {
        printf("Make a choice ");
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            calc.max();
            continue;
        case 2:
            calc.count();
            continue;
        case 3:
            calc.passRate();
            continue;
        case 4:
            printf("Please enter instructor ID");
            cin >> instructorId;
            calc.wInstructorRate(instructorId);
            continue;
        case 5:
            printf("Please enter course number");
            cin >> courseno;
            calc.wCourseRate(courseno);
            continue;
        case 6:
            printf("Please enter student ID");
            cin >> studentId;
            controller.searchStudent(studentId);
            continue;
        case 7:
            controller.enroll();
            continue;
        case 8:
            controller.update();
            continue;
        case 0:
            return;
        default:
            return;
        }
    }
}

int main()
{
    auto start = std::chrono::system_clock::now();
    time_t start_time = chrono::system_clock::to_time_t(start);
    string timeStart = ctime(&start_time);

    cout << "\nStart time " << timeStart << endl;
    write("\nStart time " + timeStart);

    commands();

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = chrono::system_clock::to_time_t(end);
    string endTime = ctime(&end_time);
    string duration = IntToString(elapsed_seconds.count());

    cout << "\nFinished computation at " << endTime
         << "elapsed time: " << duration << "s\n";
    write("\nFinished computation at " + endTime + "elapsed time: " + duration + "s\n");
    return 0;
}