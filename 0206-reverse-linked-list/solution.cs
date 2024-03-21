public class Solution {
    public ListNode ReverseList(ListNode head) {
        if(head == null) return head;
        ListNode curr = head;
        ListNode pre = null;
        ListNode nxt = curr.next;
        while(nxt != null){
            curr.next = pre;
            pre = curr;
            curr = nxt;
            nxt = nxt.next;
        }
        curr.next = pre;
        return curr;
    }
}
