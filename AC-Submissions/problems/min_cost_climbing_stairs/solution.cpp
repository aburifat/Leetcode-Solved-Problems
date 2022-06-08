class Solution {
    int dp[1010];
    vector<int>vals;
public:
    void init(int n, int x, int y){
        for(int i=0;i<n;i++)dp[i]=-1;
        dp[n-1]=y;
        dp[n-2]=x;
    }
    int goBro(int n){
        if(dp[n]!=-1)return dp[n];
        dp[n]=vals[n];
        int tmp=min(goBro(n+1),goBro(n+2));
        dp[n]+=tmp;
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vals=cost;
        int len=cost.size();
        init(len,cost[len-2],cost[len-1]);
        int ans=goBro(0);
        ans=min(dp[0],dp[1]);
        return ans;
    }
};