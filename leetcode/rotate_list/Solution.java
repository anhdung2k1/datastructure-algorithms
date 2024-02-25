package leetcode.rotate_list;
import java.util.*;

/** Definition for singly-linked list.*/
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k == 0) {
            return head;
        }

        int numNodes = 1;
        ListNode tail = head;
        while(tail.next != null) {
            tail = tail.next;
            numNodes++;
        }
        k %= numNodes;
        tail.next = head;
        for(int i = 0;i < numNodes - k;i++) {
            tail=tail.next;
            head=head.next;
        }
        tail.next=null;
        return head;
    }
}