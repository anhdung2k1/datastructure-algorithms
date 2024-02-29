#include "Employee.h"

Employee::Employee(const char empId[8], const char empName[20], char empStatus, int childs, const char empEduLevel[2], long baseSalary) 
    : numOfChilds(childs), baseSalary(baseSalary) {
    // Constraint values
    // if (this->numOfChilds > 20 || this->baseSalary > 1000000) {
    //     cout << "Invalid values, try to reinitialize" << endl;
    //     exit(1);
    // }
    // Copy empId, empName, and empEduLevel using strcpy
    strcpy(this->employeeId, empId);
    strcpy(this->employeeName, empName);
    strcpy(this->employeeEduLevel, empEduLevel);

    // Set empStatus directly
    this->employeeStatus = empStatus;
}

char* Employee::getEmployeeId()  {
    return employeeId;
}

char* Employee::getEmployeeName() {
    return employeeName;
}

char Employee::getEmployeeStatus() {
    return employeeStatus;
}

int Employee::getNumberOfChilds() {
    return numOfChilds;
}

char* Employee::getEmployeeEduLevel() {
    return employeeEduLevel;
}

long Employee::getBaseSalary() {
    return baseSalary;
}

void Employee::setEmployeeId(char* empId) {
    strcpy(this->employeeId, empId);
}

void Employee::setEmployeeName(char* name) {
    strcpy(this->employeeName, name);
}

void Employee::setEmployeeStatus(char status) {
    this->employeeStatus = status;
}

void Employee::setNumberOfChild(int num) {
    this->numOfChilds = num;
}

void Employee::setEmployeeEduLevel(char* eduLevel) {
    strcpy(this->employeeEduLevel, eduLevel);
}

void Employee::setBaseSalary(long salary) {
    this->baseSalary = salary;
}

void Employee::showInfo() {
    cout << "============Employee Info===============\n";
    cout << "Employee ID: " << this->employeeId << endl;
    cout << "Employee Name: " << this->employeeName << endl;
    cout << "Employee Status: " << this->employeeStatus << endl;
    cout << "Number of childs: " << this->numOfChilds << endl;
    cout << "Employee Education Level: " << this->employeeEduLevel << endl;
    cout << "Base Salary: " << this->baseSalary << endl;
    cout << "==============================\n";
}