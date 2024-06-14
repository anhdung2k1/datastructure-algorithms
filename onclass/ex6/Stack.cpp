#include <iostream>
using namespace std;

struct LinkedList {
    char data;
    LinkedList* next;

    LinkedList(char c) {
        this->data = c;
        this->next = NULL;
    }
};

class Stack {
    private:
        LinkedList* top;
    public:
        Stack() {
            top = NULL;
        }

        void push(char data) {
            LinkedList* tmp = new LinkedList(data);

            if (!tmp) {
                cout << "Stack empty" << endl;
                exit(1);
            }
            tmp->data = data;
            tmp->next = top;
            top = tmp;
        }

        bool isEmpty() {
            return top == NULL;
        }

        char peek() {
            if (!isEmpty())
                return top->data;
            else
                exit(1);
        }

        void pop() {
            LinkedList* tmp;
            if (isEmpty()) {
                cout << "Stack empty" << endl;
                exit(1);
            }
            else {
                tmp = top;
                top = top->next;
                free(tmp);
            }
        }

        void display() {
            LinkedList* tmp;
            if (isEmpty()) {
                cout << "Stack empty" << endl;
                exit(1);
            }
            else {
                tmp = top;
                while(tmp != NULL) {
                    cout << tmp->data;
                    tmp = tmp->next;
                    if (tmp != NULL) {
                        cout << " -> ";
                    }
                }
            }
        }
};