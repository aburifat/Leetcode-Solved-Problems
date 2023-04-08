class Solution {
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    void bfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if((x>=0)&&(x<n)&&(y>=0)&&(y<m)&&(grid[x][y]==1))bfs(x,y,n,m,grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = 0;
        if(n!=0){
            m = grid[0].size();
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)bfs(i,0,n,m,grid);
            if(grid[i][m-1]==1)bfs(i,m-1,n,m,grid);
            
        }
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==1)bfs(0,j,n,m,grid);
            if(grid[n-1][j]==1)bfs(n-1,j,n,m,grid);
        }
        
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)ct++;
            }
        }
        return ct;
    }
};