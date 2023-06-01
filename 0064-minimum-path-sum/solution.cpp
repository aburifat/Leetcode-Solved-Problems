class Solution {
    int n,m;
    int mx=1e9+7;
    vector<vector<int>>mem;
    int dp(int x, int y, vector<vector<int>>& grid){
        if(x<0||y<0||x>=n||y>=m)return mx;
        if(mem[x][y]!=-1)return mem[x][y];
        mem[x][y]=grid[x][y];
        if(x!=n-1||y!=m-1)mem[x][y]+=min(dp(x+1,y,grid),dp(x,y+1,grid));
        return mem[x][y];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        mem.assign(n,vector<int>(m,-1));
        int ans=dp(0,0,grid);
        return ans;
    }
};
