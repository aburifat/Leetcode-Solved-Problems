/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode root = new ListNode();
        ListNode curr = root;
        while(list1!=null&&list2!=null){
            int val;
            if(list1.val<list2.val){
                val = list1.val;
                list1=list1.next;
            }else{
                val = list2.val;
                list2=list2.next;
            }
            ListNode tmp = new ListNode(val);
            curr.next=tmp;
            curr = curr.next;
        }
        if(list1!=null){
            curr.next=list1;
        }
        if(list2!=null){
            curr.next=list2;
        }
        return root.next;
    }
}
