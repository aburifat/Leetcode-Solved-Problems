class Solution {
    vector<vector<int>>dp;
    int n;
    vector<vector<int>> st;
public:
    int ctDP(int idx, int k){
        if(idx>=n||k<=0)return 0;
        if(dp[idx][k]!=-1)return dp[idx][k];
        int m=st[idx].size();
        int sum=0;
        for(int i=0;i<=min(m,k);i++){
            if(i!=0)sum+=st[idx][i-1];
            dp[idx][k]=max(dp[idx][k],sum+ctDP(idx+1,k-i));
        }
        return dp[idx][k];
    } 
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n= piles.size();
        st=piles;
        dp.assign(n,vector<int>(k+1,-1));
        int ans = ctDP(0,k);
        return ans;
    }
};
