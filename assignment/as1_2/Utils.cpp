#include "EmployeeTrack.h"

class Utils {
    private:
        vector<EmployeeTrack> empList; // Create vector empty
    public:
        // Add Employee with information entering
        void addEmployee(bool KPIRequired) {
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
            cin >> newEmployeeId;
            cout << "Emp Name: ";
            cin.ignore();
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

        // Find the index of employee
        int findEmployee(char* empId) {
            int left = 0, right = empList.size() - 1;

            while(left <= right) {
                int mid = left + (right - left) / 2; //Prevent overflow
                
                // Check if empId is found in list
                if(strcmp(empList[mid].getEmployeeId(), empId) == 0) {
                    cout << "Found the Employee at: " << mid << endl;
                    return mid;
                }
                
                if(empList[mid].getEmployeeId() < empId) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            cout << "Could not found the Employee\n";
            return -1;
        }

        void swapEmployee(EmployeeTrack& emp1, EmployeeTrack& emp2) {
            EmployeeTrack empTemp = emp1;
            emp1 = emp2;
            emp2 = empTemp;
        }  

        int partition(vector<EmployeeTrack>&empListTrack, int low, int high) {
            long pivot = empListTrack[high].getRealSalary();
            int i = low - 1;
            for(int j = low; j <= high; j++) {
                if(empListTrack[j].getRealSalary() < pivot) {
                    i++;
                    swapEmployee(empListTrack[i], empListTrack[j]);
                }
            }
            swapEmployee(empListTrack[i+1], empListTrack[high]);
            return i+1;
        }

        void quickSortEmployeeSalInc(vector<EmployeeTrack>&empListTrack, int low, int high) {
            if(low < high) {
                int pivot = partition(empListTrack, low, high);
                quickSortEmployeeSalInc(empListTrack, low, pivot - 1); // Smaller in left
                quickSortEmployeeSalInc(empListTrack, pivot + 1, high); // Higher goes right
            }
        }

        void showEmployeeIncreasSalary() {
            quickSortEmployeeSalInc(empList, 0, empList.size() - 1);
            cout << "Report Salary in Month\n";
            for (EmployeeTrack empTrack : empList) {
                cout << empTrack.getEmployeeId() << "\t" << empTrack.getEmployeeName() << "\t" << empTrack.getRealSalary() << endl;
            }
        }

        // Delete the employee at index
        void deleteEmployee(int index) {
            // Delete the employee at index
            empList.erase(empList.begin() + index);
            cout << "Removed employee from the list !\n";
        }

        void updateInformation() {
            cout << "1. Emp NAME\n";
            cout << "2. Emp Status\n";
            cout << "3. Number of childs\n";
            cout << "4. Emp Edu Level\n";
            cout << "5. Emp Base Salary\n";
            cout << "6. Emp Permission Leave\n";
            cout << "7. Emp Non Permission Leave\n";
            cout << "8. Overday works in month\n";
            cout << "9. Working result\n";
        }

        void updateEmployeeInform(EmployeeTrack& emp, int option) {
            // Dynamic variable
            string updateValue = "";
            switch(option) {
                case 1:
                    cout << "Enter Emp Name: ";
                    cin >> updateValue;
                    emp.setEmployeeName(updateValue.data());
                    break;
                case 2:
                    cout << "Enter Emp Status: ";
                    cin >> updateValue;
                    emp.setEmployeeStatus(updateValue[0]);
                    break;
                case 3:
                    cout << "Enter nr Childs: ";
                    cin >> updateValue;
                    emp.setNumberOfChild(stoi(updateValue.data()));
                    break;
                case 4:
                    cout << "Enter Emp Edu Level: ";
                    cin >> updateValue;
                    emp.setEmployeeEduLevel(updateValue.data()); 
                    break;
                case 5:
                    cout << "Enter Emp Base Salary: ";
                    cin >> updateValue;
                    emp.setBaseSalary(stol(updateValue.data()));
                    break;
                case 6:
                    cout << "Enter Emp Permission Leave: ";
                    cin >> updateValue;
                    emp.setPermissionLeave(stoi(updateValue.data()));
                    break;
                case 7:
                    cout << "Enter Non Permission Leave: ";
                    cin >> updateValue;
                    emp.setNonPermissionLeave(stoi(updateValue.data()));
                    break;
                case 8:
                    cout << "Enter Over days worked in month: ";
                    cin >> updateValue;
                    emp.setODW(stoi(updateValue.data()));
                    break;
                case 9:
                    cout << "Enter Emp Working Result: ";
                    cin >> updateValue;
                    emp.setWorkResult(updateValue.data());
                    break;
                default:
                    cout << "Return to Found User Menu\n";
                    break;
            }
        }

        void optionHome() {
            cout << "1. Add new Employee\n";
            cout << "2. Find Employee\n";
            cout << "3. Show all Employee Salary in Month\n";
        }

        void optionEmployeeFound() {
            cout << "1. Update Employee Information\n";
            cout << "2. Delete Employee\n";
            cout << "3. Show Info\n";
        }

        void foundEmployeeOption(int &indexOfEmp) {
            int n;
            do {
                optionEmployeeFound();
                cout << "\nMake your choice: ";
                cin >> n;
                switch(n) {
                    case 1:
                        int optionUpdate;
                        do {
                            updateInformation();
                            cout << "Choose the information you want to update: ";
                            cin >> optionUpdate;
                            updateEmployeeInform(empList[indexOfEmp], optionUpdate);
                        } while(optionUpdate != -1);
                        break;
                    case 2:
                        // Delete employee from the list
                        deleteEmployee(indexOfEmp);
                        n = -1;
                        break;
                    default:
                        empList[indexOfEmp].showInfo();
                        break;
                }
            } while(n != -1);
        }

        // Parse parameters as reference to mapping directly in main function executed
        void showTable() { 
            int n, indexOfEmp;
            char empId[20];
            do {
                bool kpiRequired = false;
                string option="";
                optionHome();
                cout << "\nMake your choice: ";
                cin >> n;
                switch(n) {
                    case 1:
                        cout << "Would you like to add KPI information ? (yes/no): ";
                        cin >> option;
                        kpiRequired = (option == "yes" ? true : false);
                        addEmployee(kpiRequired);
                        break;
                    case 2:
                        cout << "Enter Employee ID: ";
                        cin >> empId;
                        indexOfEmp = findEmployee(empId);
                        if(indexOfEmp != -1) {
                            foundEmployeeOption(indexOfEmp);
                        }
                        break;
                    default:
                        showEmployeeIncreasSalary();
                        break;
                }

            } while(n != -1);
        }
};