public class Solution {
    private int mod = 1000000007;
    private int solve(int b, int n, int x, int[][] dp){
        if(n<=0) return 0;
        int val = (int)Math.Pow(b,x);
        if(val>n)return 0;
        if(val==n)return 1;
        if(dp[b][n] != -1) return dp[b][n];
        return dp[b][n] = (solve(b+1,n,x,dp)%mod + solve(b+1,n-val,x,dp)%mod)%mod;
    }

    public int NumberOfWays(int n, int x) {
        int[][] dp = new int[n+1][];
        for(int i=0;i<=n;i++){
            dp[i] = new int[n+1];
            for(int j = 0; j<=n; j++){
                dp[i][j] = -1;
            }
        }
        return solve(1, n, x, dp);
    }
}
