public class Solution {
    public int MinAddToMakeValid(string s) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < s.Length; i++) {
            if(s[i] == '(') count++;
            else {
                if(count > 0) count--;
                else ans++;
            }
        }
        return ans + count;
    }
}
