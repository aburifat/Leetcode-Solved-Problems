class Solution {
public:
    vector<vector<int>>mem;
    int dx[3]={-1,0,1};
    int dy[3]={1,1,1};
    int dp(int row,int col,int& n, int& m, vector<vector<int>>& grid){
        if(row>=n||col>=m||row<0||col<0)return 0;
        if(mem[row][col]!=-1)return mem[row][col];
        int ans=0;
        for(int i=0;i<3;i++){
            int new_row=row+dx[i];
            int new_col=col+dy[i];
            if(new_row<0||new_col<0||new_row>=n||new_col>=m)continue;
            if(grid[row][col]<grid[new_row][new_col]){
                ans=max(ans,1+dp(new_row,new_col,n,m,grid));
            }
        }
        return mem[row][col]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        mem.assign(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp(i,0,n,m,grid));
        }
        return ans;
    }
};
