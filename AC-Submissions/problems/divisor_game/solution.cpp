class Solution {
    int dp[1010];
public:
    void init(){
        for(int i=0;i<1010;i++)dp[i]=-1;
        dp[0]=0;
        dp[1]=0;
    }
    int ctDp(int n){
        if(dp[n]!=-1)return dp[n];
        else{
            int val=0;
            for(int i=1;i<=sqrt(n)+1;i++){
                if(n%i==0){
                    int tmp=1+ctDp(n-i);
                    tmp%=2;
                    val=max(val,tmp);
                }
            }
            return dp[n]=val;
        }
    }
    bool divisorGame(int n) {
        init();
        int ans=ctDp(n);
         if(ans%2==0)return false;
        else return true;
    }
};