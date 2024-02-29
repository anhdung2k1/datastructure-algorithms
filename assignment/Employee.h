#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <bits/stdc++.h>

using namespace std;

class Employee {
protected:
    char employeeId[8];
    char employeeName[20];
    char employeeStatus; //M: Married, S: Single
    int numOfChilds;
    char employeeEduLevel[2]; // C1: Primary, C2: Middle, C3: High, ĐH: University, CH: Master
    long baseSalary;
public:
    // Define Constructor
    Employee(const char empId[8], const char empName[20], char empStatus, int childs, const char empEduLevel[2], long baseSalary);
    // Construct getter and setters for each attribute
    char* getEmployeeId();
    char* getEmployeeName();
    char getEmployeeStatus() ;
    int getNumberOfChilds() ;
    char* getEmployeeEduLevel() ;
    long getBaseSalary();
    void setEmployeeId(char* empId);
    void setEmployeeName(char* name);
    void setEmployeeStatus(char status);
    void setNumberOfChild(int num);
    void setEmployeeEduLevel(char* eduLevel);
    void setBaseSalary(long salary);
    
    void showInfo();
};

#endif