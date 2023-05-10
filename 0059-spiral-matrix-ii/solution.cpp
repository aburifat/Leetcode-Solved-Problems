class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int total=(n*n);
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int x=0,y=0;
        int dir=0;
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=1;i<=total;i++){
            ans[x][y]=i;
            int xx=x+dx[dir];
            int yy=y+dy[dir];
            if(xx<0||yy<0||xx>=n||yy>=n||ans[xx][yy]!=0){
                dir=(dir+1)%4;
            }
            x=x+dx[dir];
            y=y+dy[dir];
        }
        return ans;
    }
};
