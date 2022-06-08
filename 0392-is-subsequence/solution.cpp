class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s=s.size();
        int len_t=t.size();
        if(len_s==0)return true;
        int ck=0;
        for(int i=0,j=0;i<len_s&&j<len_t;){
            if(s[i]==t[j]){
                if(i==len_s-1){
                    ck=1;
                    break;
                }
                i++;
                j++;
            }else j++;
        }
        if(!ck)return false;
        else return true;
    }
};
