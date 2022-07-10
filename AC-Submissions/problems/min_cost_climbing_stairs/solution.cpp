class Solution {
    int dp[1010];
public:
    int ctDp(int idx, vector<int>& cost){
        if(idx==0||idx==1)return cost[idx];
        if(dp[idx]!=-1)return dp[idx];
        dp[idx]=cost[idx]+min(ctDp(idx-1,cost),ctDp(idx-2,cost));
        return dp[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        for(int i=0;i<1010;i++)dp[i]=-1;
        return min(ctDp(len-2,cost),ctDp(len-1,cost));
    }
};