class Solution {
    int dp[50];
public:
    void init(){
        for(int i=0;i<50;i++)dp[i]=-1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
    }
    int goBabe(int n){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=goBabe(n-1)+goBabe(n-2);
    }
    int climbStairs(int n) {
        init();
        return goBabe(n);
    }
};
