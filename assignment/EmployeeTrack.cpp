#include "EmployeeTrack.h"

EmployeeTrack::EmployeeTrack(const char empId[8], const char empName[20], char empStatus, int childs, const char empEduLevel[2], long baseSalary,
                            int pLeave, int npLeave, int odwInMonth, const char workRes[2]) 
    : Employee(empId, empName, empStatus, childs, empEduLevel, baseSalary),
      permissionLeave(pLeave), nonPermissionLeave(npLeave), overDaysWorkInMonth(odwInMonth) {
        // Constraint values
        // if (this->permissionLeave > 28 || this->nonPermissionLeave > 28 || this->overDaysWorkInMonth > 28 || this->realSalary > 2000000) {
        //     cout << "Invalid values, try to reinitialize" << endl;
        //     exit(1);
        // }
        strcpy(this->workResult, workRes);
        if (this->numOfChilds > 2) {
            this->addSal += this->baseSalary * 0.05;
        }
        if (strcmp(this->employeeEduLevel, "CH") == 0) {
            this->addSal += this->baseSalary * 0.1;
        }
        if (this->overDaysWorkInMonth > 0) {
            this->addSal += this->baseSalary * 0.04 * this->overDaysWorkInMonth;
        }
        if (this->nonPermissionLeave > 0) {
            this->addSal -= this->baseSalary * 0.05 * this->nonPermissionLeave;
        }
        this->realSalary = this->baseSalary + this->addSal;
    }

int EmployeeTrack::getPermissionLeave() {
    return permissionLeave;
}

int EmployeeTrack::getNonPermissionLeave() {
    return nonPermissionLeave;
}

int EmployeeTrack::getOverDaysWorkInMonth() {
    return overDaysWorkInMonth;
}

char* EmployeeTrack::getWorkResult() {
    return workResult;
}

long EmployeeTrack::getRealSalary() {
    return realSalary;
}

void EmployeeTrack::setPermissionLeave(int pLeave) {
    this->permissionLeave = pLeave;
}

void EmployeeTrack::setNonPermissionLeave(int npLeave) {
    this->nonPermissionLeave = npLeave;
}

void EmployeeTrack::setODW(int odw) {
    this->overDaysWorkInMonth = odw;
}

void EmployeeTrack::setWorkResult(char* workResult) {
    strcpy(this->workResult, workResult);
}

void EmployeeTrack::showInfo() {
    // Get the Employee info
    Employee::showInfo();
    // Define new Info override
    cout << "============Employee Tracking===============\n";
    cout << "Employee Permission Leave: " << this->permissionLeave << endl;
    cout << "Employee Permission Non Leave: " << this->nonPermissionLeave << endl;
    cout << "Overday work in month: " << this->overDaysWorkInMonth << endl;
    cout << "Result KPI: " << this->workResult << endl;
    cout << "Real Salary: " << this->realSalary << endl;
    cout << "==============================\n";
}