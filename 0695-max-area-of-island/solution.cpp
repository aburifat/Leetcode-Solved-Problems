class Solution {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int visit(vector<vector<int>>& grid, int x, int y){
        int siz=1;
        queue<pair<int,int>>q;
        q.push({x,y});
        grid[x][y]=0;
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int u=x+dx[i];
                int v=y+dy[i];
                if(u>=0&&u<grid.size()&&v>=0&&v<grid[0].size()){
                    if(grid[u][v]==1){
                        grid[u][v]=0;
                        q.push({u,v});
                        siz++;
                    }
                }
            }
        }
        return siz;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans=max(ans,visit(grid,i,j));
                }
            }
        }
        return ans;
    }
};
