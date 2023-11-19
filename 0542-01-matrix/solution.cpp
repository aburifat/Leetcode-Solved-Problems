class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int,int>>que;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j]==0) que.push({i,j});
                else mat[i][j] = -1;
            }
        }
        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            int dis = mat[row][col];
            for(int i=0;i<4;i++){
                int x = row + dx[i];
                int y = col + dy[i];
                if(x>=0 && x<rows && y>=0 && y<cols && mat[x][y]==-1){
                    mat[x][y] = dis + 1;
                    que.push({x,y});
                }
            }
        }
        return mat;
    }
};
