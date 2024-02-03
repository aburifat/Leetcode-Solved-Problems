public class Solution {
    int[] dp;
    int solve(int[] arr, int startIndex, int len, int k){
        if(startIndex==len) return 0;
        if(dp[startIndex]!=-1)return dp[startIndex];
        int mx = 0;
        dp[startIndex] = 0;
        for(int endIndex=startIndex;endIndex<len && endIndex<startIndex+k; endIndex++){
            mx = Math.Max(mx, arr[endIndex]);
            dp[startIndex] = Math.Max(dp[startIndex], mx*(endIndex - startIndex + 1) + solve(arr,endIndex+1,len,k));
        }
        return dp[startIndex];
    }
    public int MaxSumAfterPartitioning(int[] arr, int k) {
        int len = arr.Length;
        dp = new int[len];
        for(int i=0;i<len;i++)dp[i]=-1;
        return solve(arr,0,len,k);
    }
}
