class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        s="$"+s+'^';
        int idx=0;
        int siz=0;
        for(int i=1;i<=len;i++){
            int bgLen=0;
            while(s[i-bgLen]==s[i+bgLen])bgLen++;
            if((bgLen*2-1)>siz){
                siz=(bgLen*2-1);
                idx=(i-bgLen+1);
            }
        }
        for(int i=1;i<=len;i++){
            int bgLen=0;
            int j=i-1;
            while(s[j-bgLen]==s[i+bgLen])bgLen++;
            if((bgLen*2)>siz){
                siz=(bgLen*2);
                idx=(j-bgLen+1);
            }
        }
        string ans=s.substr(idx,siz);
        return ans;
    }
};