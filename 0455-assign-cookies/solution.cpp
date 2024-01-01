class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        for(int i=0,j=0;i<(int)g.size()&&j<(int)s.size();){
            if(s[j]<g[i])j++;
            else{
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};
