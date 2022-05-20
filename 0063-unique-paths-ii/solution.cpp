class Solution {
    int dp[110][110];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=0;
        if(n>0)m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)dp[0][0]=0;
        else dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0)continue;
                dp[i][j]=0;
                if(obstacleGrid[i][j]!=1){
                    if(i>0)dp[i][j]+=dp[i-1][j];
                    if(j>0)dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
