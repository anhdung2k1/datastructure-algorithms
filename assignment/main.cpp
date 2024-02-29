#include "EmployeeTrack.h"

int main() {
    EmployeeTrack* emp = new EmployeeTrack("AD12", "Anh Dung", 'M', 2, "CH", 170000, 5, 2, 10, "T");
    cout << emp->getEmployeeName() << endl;
    emp->showInfo();
    delete emp;
    return 0;
}