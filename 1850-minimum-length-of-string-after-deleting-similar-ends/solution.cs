public class Solution {
    public int MinimumLength(string s) {
        char ch;
        int l = 0, r = s.Length - 1;
        while(l < r){
            ch = s[l];
            if(s[l] == s[r]){
                while(l <= r && s[l] == ch) l++;
                while(l < r && s[r] == ch) r--;
            }
            else break;
        }
        return r - l + 1;
    }
}
