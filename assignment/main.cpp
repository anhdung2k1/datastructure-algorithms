#include "EmployeeTrack.h"

void addEmployee(vector<EmployeeTrack>& empList, bool KPIRequired) {
    char newEmployeeId[8];
    char newEmployeeName[20];
    char newEmployeeStatus; //M: Married, S: Single
    int nrChilds;
    char newEmployeeEduLevel[2]; // C1: Primary, C2: Middle, C3: High, ĐH: University, CH: Master
    long newBaseSalary;
    // KPI default
    int permissionLeave = 0;
    int nonPermissionLeave = 0;
    int overDaysWorkInMonth = 0;
    char workResult[2]; //T: Good, TB: Good enough, K: Unestimate
    cout << "Enter information of new employee\n";
    cout << "Emp ID: ";
    cin.clear();
    cin.sync();
    cin.getline(newEmployeeId, 8);
    cout << "Emp Name: ";
    cin.getline(newEmployeeName, 20);
    cout << "Emp Status: ";
    cin >> newEmployeeStatus;
    cout << "Num of Childs: ";
    cin >> nrChilds;
    cout << "Emp Edu Level: ";
    cin >> newEmployeeEduLevel;
    cout << "Emp Base Salary: ";
    cin >> newBaseSalary;
    if(KPIRequired == true) {
        cout << "Permission Leave: ";
        cin >> permissionLeave;
        cout << "Non Permission Leave: ";
        cin >> nonPermissionLeave;
        cout << "Over Days Work In Month: ";
        cin >> overDaysWorkInMonth;
        cout << "Work Result: ";
        cin >> workResult;
    }
    // Push back to list
    empList.push_back(EmployeeTrack(newEmployeeId, newEmployeeName, newEmployeeStatus, nrChilds, newEmployeeEduLevel,
                newBaseSalary, permissionLeave, nonPermissionLeave, overDaysWorkInMonth, workResult));
}

int findEmployee(vector<EmployeeTrack>& empList, char* empId) {
    int left = 0, right = empList.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2; //Prevent overflow
        
        // Check if empId is found in list
        if(strcmp(empList[mid].getEmployeeId(), empId) == 0) {
            return mid;
        }
        
        if(empList[mid].getEmployeeId() < empId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void deleteEmployee(vector<EmployeeTrack>& empList, char* empId) {
    int indexOfEmp = findEmployee(empList, empId); //Found employee else return -1
    if (indexOfEmp == -1) {
        cout << "Cannot found the employee in list\n";
        return;
    }
    // Delete the employee at index
    empList.erase(empList.begin() + indexOfEmp);
    cout << "Removed employee from the list !\n";
}

void updateEmployeeInform(vector<EmployeeTrack>& empList, char* empId, EmployeeTrack emp) {
    int indexOfEmp = findEmployee(empList, empId);
    if (indexOfEmp == -1) {
        cout << "Cannot found the employee in list\n";
        return;
    }

    empList[indexOfEmp].setEmployeeId(emp.getEmployeeId());
    empList[indexOfEmp].setEmployeeName(emp.getEmployeeName());
    empList[indexOfEmp].setEmployeeStatus(emp.getEmployeeStatus());
    empList[indexOfEmp].setNumberOfChild(emp.getNumberOfChilds());
    empList[indexOfEmp].setEmployeeEduLevel(emp.getEmployeeEduLevel());
    empList[indexOfEmp].setBaseSalary(emp.getBaseSalary());
    empList[indexOfEmp].setPermissionLeave(emp.getPermissionLeave());
    empList[indexOfEmp].setNonPermissionLeave(emp.getNonPermissionLeave());
    empList[indexOfEmp].setODW(emp.getOverDaysWorkInMonth());
    empList[indexOfEmp].setWorkResult(emp.getWorkResult());
}

void showTable() {
    cout << "Make your choice";
}

int main() {
    vector<EmployeeTrack> employeeList; // Create vector has size 50 employees
    addEmployee(employeeList, false);
    for(auto emp : employeeList) {
        emp.showInfo();
    }
    return 0;
}