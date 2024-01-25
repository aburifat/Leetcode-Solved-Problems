class Solution {
    vector<vector<int>>dp;
    int solve(int i,int j, string& a, string& b){
        if(i>=a.size()||j>=b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=max(solve(i,j+1,a,b),solve(i+1,j,a,b));
        if(a[i]==b[j])dp[i][j]=max(dp[i][j],1+solve(i+1,j+1,a,b));
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size(),vector(text2.size(),-1));
        return solve(0,0,text1,text2);
    }
};
