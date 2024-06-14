#include <iostream>
#include <vector>
#include "CustomMap.h"

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Câu 1: Xóa phần tử trùng lặp trong danh sách liên kết kép
    void removeDuplicates() {
        if (!head) {
            return;
        }

        // Tập hợp để theo dõi các giá trị đã gặp
        CustomMap seen;        
        Node* currentNode = head;

        while (currentNode) {
            // Nếu giá trị đã có trong tập hợp `seen`
            if (seen.find(currentNode->data) != currentNode->data) {
                // Thêm giá trị vào tập hợp `seen`
                seen.insert(currentNode->data, currentNode->data);
                // Di chuyển đến nút tiếp theo
                currentNode = currentNode->next;
            } else {
                // Xóa nút hiện tại
                Node* prevNode = currentNode->prev;
                Node* nextNode = currentNode->next;

                // Cập nhật các con trỏ để xóa nút hiện tại
                if(prevNode) {
                    prevNode->next = nextNode;
                } else {
                    head = nextNode;  // Cập nhật `head` nếu nút đầu bị xóa
                }

                if (nextNode) {
                    nextNode->prev = prevNode;
                } else {
                    tail = prevNode; // Cập nhật `tail` nếu nút cuối bị xóa
                }

                // Giải phóng bộ nhớ của nút hiện tại
                Node* nodeToDelete = currentNode;
                currentNode = nextNode;
                delete nodeToDelete;
            }
        }
    }

    // Câu 2: Xóa tất cả các nút trong danh sách liên kết kép có giá trị lớn hơn giá trị cho trước
    void removeAllTargetValueGreater(int target) {
        if (!head) {
            return;
        }

        Node* currentNode = head;
        while(currentNode) {
            if (target < currentNode->data) {
                // Xóa nút hiện tại
                Node* prevNode = currentNode->prev;
                Node* nextNode = currentNode->next;

                // Cập nhật các con trỏ để xóa nút hiện tại
                if(prevNode) {
                    prevNode->next = nextNode;
                } else {
                    head = nextNode;  // Cập nhật `head` nếu nút đầu bị xóa
                }

                if (nextNode) {
                    nextNode->prev = prevNode;
                } else {
                    tail = prevNode; // Cập nhật `tail` nếu nút cuối bị xóa
                }

                // Giải phóng bộ nhớ của nút hiện tại
                Node* nodeToDelete = currentNode;
                currentNode = nextNode;
                delete nodeToDelete;
            }
            else {
                currentNode = currentNode->next;
            }
        }
    }

    void printList() {
        Node* currentNode = head;
        while (currentNode) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
};

// Ví dụ sử dụng
int main() {
    DoublyLinkedList dll;
    dll.append(10);
    dll.append(20);
    dll.append(10);
    dll.append(30);
    dll.append(20);

    cout << "Danh sách liên kết kép trước khi loại bỏ trùng lặp: ";
    dll.printList();

    dll.removeDuplicates();

    cout << "Danh sách liên kết kép sau khi loại bỏ trùng lặp: ";
    dll.printList();

    int targetValue = 10;
    dll.removeAllTargetValueGreater(targetValue);    

    cout << "Danh sách liên kết kép sau khi loại bỏ giá trị lớn hơn target: ";
    dll.printList();

    // MapUtil tempMap;

    // addIntoMap(tempMap,2,4);
    // // addIntoMap(4,5);
    // printMap(tempMap);
    return 0;
}
