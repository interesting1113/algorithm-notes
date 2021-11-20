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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
  
        ListNode dummy = new ListNode(-1), cur = dummy;
        int t = 0;
        while (l1 != null || l2 != null) {
            if (l1 != null) {
                t += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                t += l2.val;
                l2 = l2.next;
            }
            cur.next = new ListNode(t % 10);
            t /= 10;
            cur = cur.next;
        }
        if (t != 0) cur.next = new ListNode(t);

        return dummy.next;
    }
}