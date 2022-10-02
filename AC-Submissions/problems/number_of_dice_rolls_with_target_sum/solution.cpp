class Solution {
public:
    int dp[35][1010];
    int mod=1e9+7;
    void init(){
        for(int i=0;i<35;i++){
            for(int j=0;j<1010;j++){
                dp[i][j]=-1;
            }
        };
    }
    int ctDp(int n, int k, int target){
        if(target==0&&n==0)return 1;
        else if(target<=0||n<=0)return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        int ans=0;
        for(int i=1;i<=k;i++){
            ans+=ctDp(n-1,k,target-i);
            if(ans>=mod)ans%=mod;
        }
        return dp[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        init();
        return ctDp(n,k,target);
    }
};