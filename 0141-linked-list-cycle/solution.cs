/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public bool HasCycle(ListNode head) {
        if(head == null) return false;
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && slow != null){
            if(fast == slow) return true;
            if(fast.next != null) fast = fast.next.next;
            else fast = null;
            slow = slow.next;
        }
        return false;
    }
}
