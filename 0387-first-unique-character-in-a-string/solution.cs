public class Solution {
    public int FirstUniqChar(string s) {
        int[] ct = new int[26];
        for(int i=0;i<26;i++)ct[i]=0;
        for(int i=1;i<=(int)s.Length; i++){
            int c = s[i-1] - 'a';
            if(ct[c]==0)ct[c] = -i;
            else ct[c] = i;
        }
        int idx = int.MaxValue;
        for(int i=0;i<26;i++){
            if(ct[i]<0)idx = Math.Min(idx,-ct[i]);
        }
        if(idx == int.MaxValue)idx = -1;
        else idx = idx-1;
        return idx;
    }
}
