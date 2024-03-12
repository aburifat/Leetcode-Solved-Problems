public class Solution {
    public ListNode RemoveZeroSumSublists(ListNode head) {
        ListNode curr = head;
        int sum = 0;
        Stack<(ListNode, int)> st = new();
        Dictionary<int, ListNode> d = new();
        while(curr != null){
            sum += curr.val;
            if(sum == 0){
                head = curr.next;
                st.Clear();
                d.Clear();
            }
            else if(d.ContainsKey(sum)){
                ListNode tgt = d[sum];
                tgt.next = curr.next;
                while(st.Count != 0 && st.Peek().Item1 != tgt){
                    var (_,val) = st.Pop();
                    d.Remove(val);
                }
            }
            else{
                d.Add(sum, curr);
                st.Push((curr, sum));
            }
            curr = curr.next;
        }

        return head;
    }
}
