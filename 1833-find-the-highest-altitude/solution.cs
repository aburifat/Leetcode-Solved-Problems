public class Solution {
    public int LargestAltitude(int[] gain) {
        int ans = 0, sum=0;
        int len = gain.Length;
        for(int i=0;i<len;i++){
            sum+=gain[i];
            ans=Math.Max(sum,ans);
        }
        return ans;
    }
}
