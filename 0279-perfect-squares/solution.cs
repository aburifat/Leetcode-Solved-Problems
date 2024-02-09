public class Solution {
    private int solve(int n, int[] dp){
        if(n == 0) return 0;
        if(dp[n] != int.MaxValue) return dp[n];
        for(int i = 1; i <= Math.Floor(Math.Sqrt(n)); i++){
            dp[n] = Math.Min(dp[n], 1 + solve(n - (i*i), dp));
        }
        return dp[n];
    }

    public int NumSquares(int n) {
        int[] dp = new int[n+1];
        for(int i=0;i<=n;i++) dp[i] = int.MaxValue;
        return solve(n,dp);
    }
}
