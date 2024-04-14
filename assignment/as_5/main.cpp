#include <bits/stdc++.h>
using namespace std;

struct Student {
    char studentName[25];
    unsigned int studentID;
    double studentAvg;

    Student() : studentID(0), studentAvg(0.0) {
        strcpy(studentName, "");
    } 

    Student(const char* name, unsigned int id, double avg) : studentID(id), studentAvg(avg) {
        strcpy(studentName, name);
    }
};

struct StudentList {
    Student studentVal;
    StudentList* next;

    StudentList() : studentVal("", 0, 0.0), next(nullptr) {}

    StudentList(const Student& stdVal) : studentVal(stdVal), next(nullptr) {}

    StudentList(const Student& stdVal, StudentList* next) : studentVal(stdVal), next(next) {}
};

class Solution {
    private:
        // Merge sort
        StudentList* sortedMerge(StudentList* first, StudentList* second) {
            StudentList* result = new StudentList();
            if (first == NULL)
                return second;
            else if (second == NULL) {
                return first;
            }

            if (first->studentVal.studentAvg <= second->studentVal.studentAvg) {
                result = first;
                result->next = sortedMerge(first->next, second);
            } else {
                result = second;
                result->next = sortedMerge(first, second->next);
            }
            return result;
        }

        void splitList(StudentList* source, StudentList** firstRef, StudentList** secondRef) {
            StudentList* slow = source;
            StudentList* fast = source->next;

            while(fast != NULL) {
                fast = fast->next;
                if (fast != NULL) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            *firstRef = source;
            *secondRef = slow->next;
            slow->next = NULL;
        }

        // Radix Sort
        int getMaxStudentId(StudentList* head) {
            unsigned int maxStudentId = 0;
            while (head!= NULL) {
                maxStudentId = max(maxStudentId, head->studentVal.studentID);
                head = head->next;
            }
            return maxStudentId;
        }
    public:
        StudentList* initList() {
            StudentList *head = new StudentList();
            head->next = NULL;
            return head;
        }
        void insertList(StudentList *head, Student stdVal) {
            StudentList *newNode = new StudentList(stdVal);
            newNode->next = head->next;
            head->next = newNode;
            return;
        }

        void deleteList(StudentList *&head, Student stdVal) {
            StudentList *prev = nullptr;
            StudentList *curr = head;
            
            // If head node needs to be deleted
            if (curr != nullptr && curr->studentVal.studentID == stdVal.studentID) {
                head = curr->next;
                delete curr;
                return;
            }

            // Search for the node to delete
            while (curr != nullptr) {
                if (curr->studentVal.studentID == stdVal.studentID) {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }

         void printList(StudentList *head) {
            while(head!= nullptr) {
                cout << head->studentVal.studentName << " " << head->studentVal.studentID << " " << head->studentVal.studentAvg << endl;
                head = head->next;
            }
            return;
        }

        // Merge Sort Linked List
        void mergeSortList(StudentList** headRef) {
            StudentList* head = *headRef;
            StudentList* first;
            StudentList* second;

            if ((head == NULL) || (head->next == NULL)) {
                return;
            }

            splitList(head, &first, &second);
            mergeSortList(&first);
            mergeSortList(&second);

            *headRef = sortedMerge(first, second);
        }

        // Radix Sort Linked List
        int getMaxDigits(StudentList* head) {
            int maxDigits = 0;
            int maxNumStudentId = getMaxStudentId(head);
            while (maxNumStudentId > 0) {
                maxNumStudentId /= 10;
                maxDigits++;
            }
            return maxDigits;
        }

        void radixSortList(StudentList*& head, int maxDigits) {
            queue<StudentList*> buckets[10]; // create 10 buckets for each digit (0-9)
            for (int digit = 1; digit <= maxDigits; digit++) {
                while(head != nullptr) {
                    int dg = (head->studentVal.studentID / digit) % 10;
                    buckets[dg].push(head);
                    head = head->next;
                }

                StudentList* tail = nullptr;
                for(int i = 0; i < 10; i++) {
                    while(!buckets[i].empty()) {
                        if (tail == nullptr) {
                            head = tail = buckets[i].front();
                        } else {
                            tail->next = buckets[i].front();
                            tail = tail->next;
                        }
                        buckets[i].pop();
                    }
                }
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }
        }

        // Find the Student Information based on ID
        Student findStudentById(StudentList* head, unsigned int id) {
            Student result;
            while (head!= NULL) {
                if (head->studentVal.studentID == id) {
                    result = head->studentVal;
                    break;
                }
                head = head->next;
            }
            return result;
        }

        void printAvgIntoFile(StudentList* studentNode, string fileName) {
            ofstream file(fileName);
            while (1) {
                while(studentNode != NULL) {
                    file << studentNode->studentVal.studentAvg << " ";
                    studentNode = studentNode->next;
                }
                file << endl;
                file.close();
                break;
            }
        }

        void printIDIntoFile(StudentList* studentNode, string fileName) {
            ofstream file(fileName);
            while (1) {
                while(studentNode != NULL) {
                    file << studentNode->studentVal.studentID << " ";
                    studentNode = studentNode->next;
                }
                file << endl;
                file.close();
                break;
            }
        }

        void printStudentInformation(Student student) {
            cout << "Student Name: " << student.studentName 
                 << "\nStudent ID: " << student.studentID 
                 << "\nStudent AVG: " << student.studentAvg << endl;
        }
};

int main() {
    Solution* solution = new Solution();
    
    // Merge Sort Avg
    cout << "Merge Sort with Student Avg\n";
    string fileName = "trungbinh.txt";
    StudentList* studentNode = solution->initList();
    solution->insertList(studentNode, Student("Anh Dung", 1, 9.8));
    solution->insertList(studentNode, Student("Anh Trung", 2, 7.9));
    solution->insertList(studentNode, Student("Ha My", 6, 4.9));
    solution->insertList(studentNode, Student("Quang Trung", 4, 6.9));
    solution->deleteList(studentNode, Student("", 0, 0.0));
    solution->deleteList(studentNode, Student("Anh trung", 2, 7.9));
    solution->mergeSortList(&studentNode);
    solution->printList(studentNode);
    solution->printAvgIntoFile(studentNode, fileName);

    //  Radix Sort ID
    cout << "Radix Sort with Student ID \n";
    fileName = "ID.txt";
    int maxDigit = solution->getMaxDigits(studentNode);
    solution->radixSortList(studentNode, maxDigit);
    solution->printList(studentNode);
    solution->printIDIntoFile(studentNode, fileName);
    
    // Find the Student Information based on ID
    cout << "Find Student Information with Student ID \n";
    unsigned targetStudentID = 6;
    Student student = solution->findStudentById(studentNode, targetStudentID);
    solution->printStudentInformation(student);
    return 0;
}
