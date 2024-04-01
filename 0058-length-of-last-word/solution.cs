public class Solution {
    public int LengthOfLastWord(string s) {
        int mx = 0;
        int l = 0, r = s.Length - 1;
        while(l <= r && s[l] == ' ')l++;
        while(l <= r && s[r] == ' ')r--;
        for(int i = l; i <= r; i++){
            if(s[i] == ' ') mx = 0;
            else mx++;
        }
        return mx;
    }
}
