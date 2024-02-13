public class Solution {
    public string FirstPalindrome(string[] words) {
        string ans = "";
        for(int i=0;i<words.Length;i++){
            bool ck = true;
            for(int j=0,k=words[i].Length-1;j<k;j++,k--){
                if(words[i][j]!=words[i][k]){
                    ck=false;
                    break;
                }
            }
            if(ck){
                ans = words[i];
                break;
            }
        }
        return ans;
    }
}
