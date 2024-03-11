public class Solution {
    public string CustomSortString(string order, string s) {
        Dictionary<char,int> ct = new();
        for(int i = 0; i<26; i++){
            ct.Add((char)((int)'a' + i), 0);
        }
        foreach(char ch in s){
            ct[ch]++;
        }
        List<char> ans = new();
        foreach(char ch in order){
            while(ct[ch] > 0){
                ct[ch]--;
                ans.Add(ch);
            }
        }
        foreach(var item in ct){
            for(int i = 0; i < item.Value; i++){
                ans.Add(item.Key);
            }
        }
        return string.Join("", ans);
    }
}
