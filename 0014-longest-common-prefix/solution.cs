public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        int mx_len = strs[0].Length;
        char[] tmp = new char[mx_len];
        for(int i=0;i<mx_len;i++){
            tmp[i] = strs[0][i];
        }
        int r = mx_len;
        int len = strs.Length;
        for(int i=1;i<len; i++){
            int now_len = Math.Min(mx_len,strs[i].Length);
            mx_len = 0;
            for(int j=0;j<now_len;j++){
                if(tmp[j]==strs[i][j])mx_len=j+1;
                else break;
            }
        }
        string ans = "";
        if(mx_len>0)ans = new string(tmp, 0, mx_len);
        return ans;
    }
}
