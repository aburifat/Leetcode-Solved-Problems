class Solution {
public:
    int dx[2]={-1,0};
    int dy[2]={0,-1};
    int dp[110][110];
    int ctDp(int row, int col){
        if(row<0||col<0)return 0;
        if(row==0&&col==0)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col]=(ctDp(row+dx[0],col+dy[0])+ctDp(row+dx[1],col+dy[1]));
    }
    int uniquePaths(int m, int n) {
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++)dp[i][j]=-1;
        }
        int ans=ctDp(m-1,n-1);
        return ans;
    }
};