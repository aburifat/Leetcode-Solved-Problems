public class Solution {
    public int CountSubstrings(string s) {
        int ans=0,l,r;
        for(int i=0;i<s.Length;i++){
            l=i;r=i+1;while(l>=0&&r<s.Length&&s[l--]==s[r++])ans++;
            l=r=i;while(l>=0&&r<s.Length&&s[l--]==s[r++])ans++;
        }
        return ans;
    }
}
