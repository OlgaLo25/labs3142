#include "controller.h"
#include "write_read.h"
#include "calculations.h"

// все записать в файл
// проверка на студента, курс, на инструктора
// тесты добавить

int main(){
    vector<dataPerCourse> data = readCSV();
    Calculation calc(data);
    calc.max();
    printf("\n");
    calc.count();
    printf("\n");
    calc.passRate();
    printf("\n");
    calc.wInstructorRate("I27F");
    calc.wCourseRate(1115);
    printf("\n");
    Controller controller(data);
    controller.searchStudent("E0907");
    return 0;
}