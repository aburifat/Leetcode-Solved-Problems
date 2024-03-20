
public class Solution {
    public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int idx = 0;
        ListNode curr = list1;
        ListNode l = new();
        ListNode r = new();
        while(idx <= b + 1){
            if(idx == a - 1){
                l = curr;
            }
            if(idx == b + 1){
                r = curr;
            }
            curr = curr.next;
            idx++;
        }
        l.next = list2;
        curr = list2;
        while(true){
            if(curr.next == null){
                curr.next = r;
                break;
            }
            curr = curr.next;
        }
        return list1;
    }
}
