public class Solution {
    public int MinSwaps(string s) {
        int ans = 0;
        int stack = 0;
        for(int i = 0; i < s.Length; i++) {
            if(s[i]==']') {
                if(stack > 0) stack--;
                else {
                    stack++;
                    ans++;
                }
            }
            else stack++;
        }
        return ans;
    }
}
