#include <bits/stdc++.h>
using namespace std;

 //* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode* tail = head;
        int numNodes = 1;
        // Get the size of the nodes
        while(tail->next != NULL) {
            tail = tail->next;
            numNodes++;
        }
        cout << "Tail next value: " << tail->val << endl;
        // Assign the next last + 1 tail next pointer to head
        tail->next = head;
        // Get the remainder k rotation
        k%=numNodes;
        for(int i = 0;i<numNodes-k;i++) {
            head = head->next;
            tail = tail->next;
        }
        tail->next=NULL;
        return head;
    }
};