class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        vector<int>bks;
        bks.push_back(-1);
        for(int i=0;i<len;i++){
            if(s[i]==' ')bks.push_back(i);
        }
        bks.push_back(len);
        int ct=bks.size();
        vector<char>ans;
        for(int i=1;i<ct;i++){
            if(i!=1)ans.push_back(' ');
            for(int j=bks[i]-1;j>bks[i-1];j--){
                ans.push_back(s[j]);
            }
        }
        for(int i=0;i<len;i++){
            s[i]=ans[i];
        }
        return s;
    }
};