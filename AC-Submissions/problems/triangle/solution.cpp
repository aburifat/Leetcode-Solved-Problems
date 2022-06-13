class Solution {
    int dp[220][220];
    bool visited[220][220];
    vector<vector<int>>val;
public:
    void init(){
        for(int i=0;i<220;i++){
            for(int j=0;j<220;j++){
                dp[i][j]=0;
                visited[i][j]=false;
            }
        }
    }
    int ctDp(int x, int y, int mxIdx){
        if(visited[x][y])return dp[x][y];
        if(x==mxIdx){
            visited[x][y]=true;
            return dp[x][y]=val[x][y];
        }
        int valDown=val[x][y]+ctDp(x+1,y,mxIdx);
        int valRight=val[x][y]+ctDp(x+1,y+1,mxIdx);
        visited[x][y]=true;
        return dp[x][y]=min(valDown,valRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        val=triangle;
        int len=triangle.size();
        int ans=ctDp(0,0,len-1);
        return ans;
    }
};