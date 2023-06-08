class Solution {
public:
    vector<vector<int>>mem;
    int dp(int i, int j, int& n, int& m, vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        if(i<0||j<0||j>=m||i>=n)return 0;
        if(i==n-1)return grid[i][j];
        if(mem[i][j]!=-1)return mem[i][j];
        int cost = INT_MAX;
        int idx = grid[i][j];
        for(int j=0;j<m;j++){
            cost = min(cost, moveCost[idx][j] + idx + dp(i+1,j,n,m,grid,moveCost));
        }
        return mem[i][j]=cost;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        mem.assign(n,vector<int>(m,-1));
        int ans=dp(0,0,n,m,grid,moveCost);
        for(int i=1;i<m;i++){
            ans = min(ans,dp(0,i,n,m,grid,moveCost));
        }
        return ans;
    }
};
