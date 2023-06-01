class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int dx[8]={0,0,1,-1,1,1,-1,-1};
        int dy[8]={1,-1,0,0,1,-1,1,-1};
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        int ans=-1;
        if(grid[0][0]==0){
            q.push({{0,0},1});
            visited[0][0]=true;
        }
        while(!q.empty()){
            auto ft=q.front();
            q.pop();
            int x=ft.first.first;
            int y=ft.first.second;
            int ct=ft.second;
            if(x==n-1&&y==n-1)return ct;
            for(int i=0;i<8;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&yy>=0&&xx<n&&yy<n&&grid[xx][yy]==0&&visited[xx][yy]==false){
                    visited[xx][yy]=true;
                    q.push({{xx,yy},ct+1});
                }
            }
            if(ans!=-1)break;
        }
        return ans;
    }
};
