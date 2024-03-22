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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow!= NULL && fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode(-1);
        ListNode* mptr = merged;
        ListNode* left = list1;
        ListNode* right = list2;
        while(left != NULL && right != NULL) {
            if (left->val <= right->val) {
                mptr->next=left;
                left = left->next;
                mptr = mptr->next;
            } else {
                mptr->next=right;
                right = right->next;
                mptr = mptr->next;
            }
        }
        while (left != NULL) {
            mptr->next = left;
            mptr = mptr->next;
            left = left->next;
        }
        
        while (right != NULL) {
            mptr->next = right;
            mptr = mptr->next;
            right = right->next;
        }
        return merged->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = middleNode(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* mergedList = mergeSort(left, right);
        return mergedList;
    }
};