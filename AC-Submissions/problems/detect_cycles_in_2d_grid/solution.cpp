class Solution {
    int color[510][510];
    pair<int,int> parent[510][510];
    pair<int,int> cycle_start;
    pair<int,int> cycle_end;

    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    void init(){
        cycle_start = {-1,-1};
        cycle_end = {-1,-1};
        for(int i=0;i<510;i++){
            for(int j=0;j<510;j++){
                color[i][j]=0;
                parent[i][j]={-1,-1};
            }
        }
    }

    bool cycleDfs(int i, int j, int n, int m,vector<vector<char>>& grid){
        color[i][j]=1;
        for(int k=0;k<4;k++){
            int u_i = i+dx[k];
            int u_j = j+dy[k];
            if(u_i<0||u_i>=n||u_j<0||u_j>=m)continue;
            if(grid[i][j]!=grid[u_i][u_j])continue;
            if(color[u_i][u_j]==0){
                parent[u_i][u_j]={i,j};
                if(cycleDfs(u_i,u_j,n,m,grid))return true;
            }else{
                //Undirected Graph
                int par_i = parent[i][j].first;
                int par_j = parent[i][j].second;
                if((u_i==par_i) && (u_j==par_j))continue;

                //Directed Graph
                //if(color[u_i][u_j]==2)continue;

                //Common
                cycle_end = {i,j};
                cycle_start = {u_i,u_j};
                return true;
            }
        }
        color[i][j]=2;
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        init();
        int n = grid.size();
        int m = 0;
        if(n>0)m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(color[i][j]==0&&cycleDfs(i,j,n,m,grid)){
                    return true;
                }
            }
        }
        return false;
    }
};