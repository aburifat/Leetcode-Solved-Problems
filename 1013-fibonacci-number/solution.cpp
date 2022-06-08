class Solution {
    vector<int>dp;
public:
    void init(int n){
        dp.assign(n+5,-1);
    }
    int ctFib(int n){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=ctFib(n-1)+ctFib(n-2);
    }
    int fib(int n) {
        init(n);
        dp[0]=0;
        dp[1]=1;
        int ans=ctFib(n);
        return ans;
    }
};
