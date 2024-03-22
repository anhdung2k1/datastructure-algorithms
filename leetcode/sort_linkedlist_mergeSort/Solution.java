/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) {
            return head;
        }

        ListNode ptr = head;
        List<Integer> listArr = new ArrayList<>();
        while(ptr != null) {
            listArr.add(ptr.val);
            ptr = ptr.next;
        }
        Collections.sort(listArr);
        ListNode n = new ListNode(listArr.get(0));
        head = n;
        ListNode temp = head;
        for(int i = 1; i < listArr.size(); i++) {
            ListNode n1 = new ListNode(listArr.get(i));
            temp.next = n1;
            temp = temp.next;
        }
        return head;
    }
}