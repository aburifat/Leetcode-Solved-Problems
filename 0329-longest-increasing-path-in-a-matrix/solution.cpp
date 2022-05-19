int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
class Solution {
    map<pair<int,int>,bool>visited;
    vector<vector<int>>mat,dis;
    int n,m=0;
public:
    int getLongDis(int x, int y){
        if(dis[x][y]!=-1)return dis[x][y];
        dis[x][y]=1;
        int tmpDis=0;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<n&&yy<m&&mat[x][y]<mat[xx][yy]){
                tmpDis=max(tmpDis,getLongDis(xx,yy));
            }
        }
        return dis[x][y]=dis[x][y]+tmpDis;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        mat=matrix;
        n=matrix.size();
        if(n>0)m=matrix[0].size();
        dis.assign(n+5,vector<int>(m+5,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=getLongDis(i,j);
                ans=max(ans,val);
            }
        }
        return ans;
    }
};
