#include <iostream>
using namespace std;

struct QNode {
    char data;
    QNode* next;

    QNode(char c) {
        data = c;
        next = NULL;
    }
};

class Queue {
    private:
        QNode* front, *rear;
    public:
        Queue() {
            this->front = NULL;
            this->rear = NULL;
        }

        void enQueue(char c) {
            QNode* tmp = new QNode(c);

            if (rear == NULL) {
                front = rear = tmp;
                return;
            }
            
            rear->next = tmp;
            rear = tmp;
        }

        void deQueue() {
            if (front == NULL) {
                return;
            }

            QNode* tmp = front;
            front = front->next;

            if (front == NULL) {
                rear = NULL;
            }

            delete (tmp);
        }

        char getFront() {
            return front != NULL ? (front)->data : -1;
        }
};