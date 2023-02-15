public class Solution {
    public IList<int> AddToArrayForm(int[] num, int k) {
        IList<int> ans = new List<int>();
        int len = num.Length;
        int carry=0;
        for(int i=len-1;i>=0;i--){
            int val=carry+num[i];
            if(k!=0){
                val+=(k%10);
                k/=10;
            }
            carry=val/10;
            val=val%10;
            num[i]=val;
        }
        k+=carry;
        for(int i=0;i<len;i++){
            ans.Add(num[i]);
        }
        while(k!=0){
            ans.Insert(0,k%10);
            k/=10;
        }
        return ans;
    }
}
