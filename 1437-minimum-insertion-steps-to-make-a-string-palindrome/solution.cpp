class Solution {
public:
    vector<vector<int>>dp;
    int ctDP(int i, int j, string& s){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])dp[i][j]=ctDP(i+1,j-1,s);
        else{
            dp[i][j]=1+min(ctDP(i,j-1,s),ctDP(i+1,j,s));
        }
        return dp[i][j];
    }
    int minInsertions(string s) {
        int len=s.size();
        dp.assign(len,vector<int>(len,-1));
        int ans=ctDP(0,len-1,s);
        return ans;
    }
};
