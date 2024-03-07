public class Solution {
    public ListNode MiddleNode(ListNode head) {
        int len = 0;
        ListNode curr = head;
        while(curr!=null){
            len++;
            curr = curr.next;
        }
        int idx = (len / 2);
        curr = head;
        while(idx > 0){
            curr = curr.next;
            idx--;
        }
        return curr;
    }
}
