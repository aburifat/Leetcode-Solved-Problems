class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    if(i==0)ans+=grid[i][j];
                    else if(grid[i-1][j]<grid[i][j])ans+=(grid[i][j]-grid[i-1][j]);
                    if(j==0)ans+=grid[i][j];
                    else if(grid[i][j-1]<grid[i][j])ans+=(grid[i][j]-grid[i][j-1]);
                    if(i==n-1)ans+=grid[i][j];
                    else if(grid[i+1][j]<grid[i][j])ans+=(grid[i][j]-grid[i+1][j]);
                    if(j==m-1)ans+=grid[i][j];
                    else if(grid[i][j+1]<grid[i][j])ans+=(grid[i][j]-grid[i][j+1]);
                    ans+=2;
                }
            }
        }
        return ans;
    }
};