public class Solution {
    private ListNode reverse(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    private ListNode findMiddle(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public void ReorderList(ListNode head) {
        ListNode mid = findMiddle(head);
        ListNode rev = reverse(mid.next);
        mid.next = null;
        ListNode curr = head;
        while(curr != null && rev != null){
            ListNode currNext = curr.next;
            ListNode revNext = rev.next;
            curr.next = rev;
            rev.next = currNext;
            curr = currNext;
            rev = revNext;
        }
    }
}
