public class Solution {
    int n,m;
    int mod = (int)1e9+7;
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    public int FindPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int[,,] dp = new int[m,n,maxMove + 1];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<=maxMove;k++){
                    dp[i,j,k]=-1;
                }
            }
        }
        this.m = m;
        this.n = n;
        return solve(maxMove,startRow,startColumn,dp);
    }

    private int solve(int maxMove, int x, int y, int[,,] dp){
        if(x<0 || x>=m || y<0 || y>=n) return 1;
        if(maxMove <= 0) return 0;
        if(dp[x,y,maxMove]!=-1){
            return dp[x,y,maxMove];
        }

        int ans = 0;
        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            ans += solve(maxMove-1,xx,yy,dp);
            ans%=mod;
        }
        return dp[x,y,maxMove] = ans;
    }
}
