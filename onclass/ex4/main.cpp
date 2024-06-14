#include <iostream>
#include <vector>
using namespace std;

struct DoubleList {
    int val;
    DoubleList* next;
    DoubleList* pre;
};

DoubleList* getNode(int value) {
    DoubleList* newNode = (struct DoubleList*)malloc(sizeof(struct DoubleList));
    newNode->val = value;
    newNode->pre = newNode->next = NULL;
    return newNode;
}

void addHead(DoubleList** head, int value) {
    DoubleList* newNode = (struct DoubleList*)malloc(sizeof(struct DoubleList));
    newNode->val = value;
    newNode->next = (*head);
    newNode->pre = NULL;
    if ((*head) != NULL)
      (*head)->pre = newNode;
    (*head) = newNode;
}

// Insertion sort
void sortedInsert(DoubleList** head, DoubleList* newNode) {
    DoubleList* current;
    if(*head == NULL) {
        *head = newNode;
    }
    else if ((*head)->val >= newNode->val) {
        newNode->next = *head;
        newNode->next->pre = newNode;
        *head = newNode;
    }
    else {
        current = *head;
        while(current->next != NULL && current->next->val < newNode->val) {
            current = current->next;
        }
        newNode->next = current->next;

        if (current->next != NULL) 
            newNode->next->pre = newNode;
        current->next = newNode;
        newNode->pre = current;
    }
}

void insertionSort(DoubleList** head) {
    DoubleList* sorted = NULL;
    DoubleList* current = *head;
    while(current != NULL) {
        DoubleList* next = current->next;
        current->pre = current->next = NULL;
        // Thêm current vào 'sorted' double single linked list
        sortedInsert(&sorted, current);
        current = next;
    }
    *head = sorted;
}

// Merge sort

DoubleList* merge(DoubleList* headB, DoubleList* headC) {
    DoubleList dummy;
    DoubleList* tail = &dummy;

    DoubleList* currentB = headB;
    DoubleList* currentC = headC;

    while(currentB != NULL && currentC != NULL) {
        if (currentB->val <= currentC->val) {
            tail->next = currentB;
            currentB->pre = tail;
            currentB = currentB->next;
        }
        else {
            tail->next = currentC;
            currentC->pre = tail;
            currentC = currentC->next;
        }
        tail = tail->next;
    }

    if (currentB != NULL) {
        tail->next = currentB;
        currentB->pre = tail;
    }
    else if (currentC != NULL) {
        tail->next = currentC;
        currentC->pre = tail;
    }
    if (dummy.next != NULL) {
        dummy.next->pre = NULL;
    }
    return dummy.next;
}

DoubleList* mergeSort(DoubleList* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    DoubleList* mid = head;
    DoubleList* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

    DoubleList* head2 = mid->next;
    mid->next->pre = nullptr;
    mid->next = nullptr;

    // Recursively sort both halves
    DoubleList* sortedHead1 = mergeSort(head);
    DoubleList* sortedHead2 = mergeSort(head2);

    // Merge the two sorted halves
    return merge(sortedHead1, sortedHead2);
}



void printList(DoubleList* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    DoubleList* head = NULL;
    vector<int>arr = {1, 4, 5, 12, 123 ,41, 2132, 412, 532, 1235, 643123, 1242354, 43251, 23135, 5563, 123};
    for(int val : arr) {
        addHead(&head,val);
    }
    printList(head);
    cout << "Sắp xếp Danh sách liên kết kép thông qua insertion sort" << endl;
    insertionSort(&head);
    printList(head);
    cout << "Sắp xếp Danh sách liên kết kép thông qua Merge Sort" << endl;
    mergeSort(head);
    printList(head);
    return 0;
}