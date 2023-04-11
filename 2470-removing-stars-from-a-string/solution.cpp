class Solution {
public:
    string removeStars(string s) {
        int idx=0;
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='*'){
                if(idx>0)idx--;
            }
            else{
                s[idx]=s[i];
                idx++;
            }
        }
        return s.substr(0,idx);
    }
};
