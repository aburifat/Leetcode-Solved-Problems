public class Solution {
    public int LengthOfLastWord(string s) {
        int len=s.Length;
        int ct=0;
        bool ck=true;
        for(int i=0;i<len;i++){
            if(s[i]==' ')ck=true;
            else{
                if(ck==true){
                    ct=0;
                    ck=false;
                }
                ct+=1;
            }
        }
        return ct;
    }
}
