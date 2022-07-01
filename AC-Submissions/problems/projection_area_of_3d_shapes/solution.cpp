class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)ans++;
            }
        }
        for(int i=0;i<n;i++){
            int mx=grid[i][0];
            for(int j=0;j<m;j++){
                mx=max(mx,grid[i][j]);
            }
            ans+=mx;
        }
        for(int i=0;i<m;i++){
            int mx=grid[0][i];
            for(int j=0;j<n;j++){
                mx=max(mx,grid[j][i]);
            }
            ans+=mx;
        }
        return ans;
    }
};