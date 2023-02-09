public class Solution {
    public int RomanToInt(string s) {
        Dictionary<char,int> dic = new Dictionary<char,int>();
        dic.Add('I', 1);
        dic.Add('V', 5);
        dic.Add('X', 10);
        dic.Add('L', 50);
        dic.Add('C', 100);
        dic.Add('D', 500);
        dic.Add('M', 1000);
        int len=s.Length;
        int ans=0;
        for(int i=len-1;i>=0;i--){
            if(i!=len-1 && dic[s[i]]<dic[s[i+1]]){
                ans -= dic[s[i]];
            }else ans += dic[s[i]];
        }
        return ans;
    }
}