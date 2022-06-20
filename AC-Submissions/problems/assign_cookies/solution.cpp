class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int len_g=g.size();
        int len_s=s.size();
        int ct=0;
        for(int i=len_g-1,j=len_s-1;i>=0&&j>=0;){
            if(g[i]<=s[j]){
                i--;
                j--;
                ct++;
            }else i--;
        }
        return ct;
    }
};