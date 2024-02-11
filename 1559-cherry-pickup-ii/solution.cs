public class Solution {
    int[,,] dp;
    int solve(int x, int y1, int y2, int n, int m, int[][] grid){
        if(x < 0 || x >= n || y1 < 0 || y1 >= m || y2 < 0 || y2 >= m) return 0;
        if(dp[x,y1,y2] != -1)return dp[x,y1,y2];
        dp[x,y1,y2] = grid[x][y1];
        if(y1 !=y2) dp[x,y1,y2] += grid[x][y2];
        int val = 0;
        int currx = x + 1;
        for(int i=-1; i<=1; i++){
            for(int j = -1; j<= 1; j++){
                int curry1 = y1 + i;
                int curry2 = y2 + j;
                val = Math.Max(val, solve(currx, curry1, curry2, n, m, grid));
            }
        }
        dp[x,y1,y2] += val;
        return dp[x,y1,y2];
    }
    public int CherryPickup(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        dp = new int[n,m,m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++)dp[i,j,k] = -1;
            }
        }
        int ans = solve(0,0,m-1,n,m,grid);
        return ans;
    }
}
