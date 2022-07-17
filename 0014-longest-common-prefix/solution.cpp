class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        int idx=strs[0].size();
        int sz0=idx;
        for(int i=1;i<len;i++){
            int sz=strs[i].size();
            int tmp=0;
            for(int j=0;j<min(sz,sz0);j++){
                if(strs[0][j]!=strs[i][j])break;
                tmp++;
                }
            idx=min(idx,tmp);
        }
        string s=strs[0].substr(0,idx);
        return s;
    }
};
