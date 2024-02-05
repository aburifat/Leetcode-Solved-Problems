public class Solution {
    public string MinWindow(string s, string t) {
        if(s == "" || t == "")return "";

        int start = 0, end = 0, startIdx = 0, rem = t.Length, minLen = int.MaxValue;

        int[] cnt = new int[128];

        for(int i=0;i<(int)t.Length; i++){
            cnt[t[i]]++;
        }

        while(end < s.Length){
            if(cnt[s[end++]]-- > 0){ // Increasing the length to get a solution
                rem--;
            }
            while(rem == 0){ // While the solution is valid
                if(minLen > end - start){ // Recording the smallest solution
                    startIdx = start;
                    minLen = end - start;
                }
                if(cnt[s[start++]]++ == 0){ //Trying to reduce from the front to minimize the solution
                    rem++;
                }
            }
        }

        return minLen == int.MaxValue ? "" : s.Substring(startIdx, minLen);

        return "";
    }
}
