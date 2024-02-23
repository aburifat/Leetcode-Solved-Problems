public class Solution {
    public int FindCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] dp = new int[n];
        Array.Fill(dp, int.MaxValue);
        dp[src] = 0;

        for (int i = 0; i <= k; i++) {
            int[] temp = (int[])dp.Clone();
            foreach (int[] flight in flights) {
                if (dp[flight[0]] != int.MaxValue) {
                    temp[flight[1]] = Math.Min(temp[flight[1]], dp[flight[0]] + flight[2]);
                }
            }
            dp = temp;
        }
        
        return dp[dst] == int.MaxValue ? -1 : dp[dst];
    }
}
