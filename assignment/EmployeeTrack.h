#ifndef EMPLOYEE_TRACK_H
#define EMPLOYEE_TRACK_H

#include "Employee.h"

// This class extends from Employee Resume Class to mainly handle the Employee Tracking
class EmployeeTrack : public Employee {
private:
    int addSal = 0;
    long realSalary;
protected:
    int permissionLeave;
    int nonPermissionLeave;
    int overDaysWorkInMonth;
    char workResult[2]; //T: Good, TB: Good enough, K: Unestimate
public:
    EmployeeTrack(const char empId[8], const char empName[20], char empStatus, int childs, const char empEduLevel[2], long baseSalary,
                int pLeave, int npLeave, int odwInMonth, const char workRes[2]);
    // Getter and Setters
    int getPermissionLeave();
    int getNonPermissionLeave();
    int getOverDaysWorkInMonth();
    char* getWorkResult();
    long getRealSalary();
    
    void showInfo();
};

#endif