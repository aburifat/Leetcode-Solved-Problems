class Solution {
public:
    int n,m;
    int mod=1e9+7;
    vector<vector<vector<int>>>mem;
    int dp(int x, int y, int sum, vector<vector<int>>& grid, int& k){
        if(x<0||y<0||x>=n||y>=m)return 0;
        sum+=grid[x][y];
        sum%=k;
        if(mem[x][y][sum]!=-1)return mem[x][y][sum];
        if(x==n-1&&y==m-1){
            if(sum==0)return 1;
            else return 0;
        }
        mem[x][y][sum]=dp(x+1,y,sum,grid,k)+dp(x,y+1,sum,grid,k);
        mem[x][y][sum]%=mod;
        return mem[x][y][sum];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        mem.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));
        int ans=dp(0,0,0,grid,k);
        return ans;
    }
};
