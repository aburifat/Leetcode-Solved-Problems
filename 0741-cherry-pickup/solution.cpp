class Solution {
public:
    vector<vector<vector<vector<int>>>>mem;
    int dp(int x1, int y1, int x2, int y2, int& n, int& m, vector<vector<int>>& grid){
        if(x1<0||y1<0||x2<0||y2<0||x1>=n||y1>=m||x2>=n||y2>=m)return INT_MIN;
        if(x1==x2&&y1==y2&&x1==n-1&&y1==m-1){
            if(grid[x1][y1]!=-1)return mem[x1][y1][x2][y2]=grid[x1][y1];
            else return mem[x1][y1][x2][y2]=INT_MIN;
        }
        if(grid[x1][y1]==-1||grid[x2][y2]==-1)return INT_MIN;
        
        if(mem[x1][y1][x2][y2]!=-1)return mem[x1][y1][x2][y2];
        int ct = INT_MIN;
        ct=max(ct,dp(x1+1,y1,x2+1,y2,n,m,grid));
        ct=max(ct,dp(x1+1,y1,x2,y2+1,n,m,grid));
        ct=max(ct,dp(x1,y1+1,x2+1,y2,n,m,grid));
        ct=max(ct,dp(x1,y1+1,x2,y2+1,n,m,grid));
        if(grid[x1][y1]==1&&ct!=INT_MIN){
            ct++;
        }
        if(!(x1==x2&&y1==y2)&&grid[x2][y2]==1&&ct!=INT_MIN){
            ct++;
        }
        return mem[x1][y1][x2][y2]=ct;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        mem.assign(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
        int ans = dp(0,0,0,0,n,m,grid);
        if(mem[n-1][m-1][n-1][m-1]==-1)ans=0;
        if(ans<0)ans=0;
        return ans;
    }
};
