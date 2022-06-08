class Solution {
    int dp[40];
public:
    void init(){
        for(int i=0;i<40;i++)dp[i]=-1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
    }
    int fib(int n){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(fib(n-1)+fib(n-2)+fib(n-3));
    }
    int tribonacci(int n) {
        init();
        return fib(n);
    }
};