typedef long long ll;
class Solution {
public:
    ll dirx[4]={0,1,0,-1};
    ll diry[4]={1,0,-1,0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ll x=0,y=0;
        ll diridx=0;
        vector<int>ans;
        ll n=matrix.size();
        ll m=matrix[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<(n*m);i++){
            ans.push_back(matrix[x][y]);
            visited[x][y]=true;
            ll newx=x+dirx[diridx];
            ll newy=y+diry[diridx];
            if(newx<0||newy<0||newx>=n||newy>=m||visited[newx][newy]==true){
                diridx=(diridx+1)%4;
            }
            x=x+dirx[diridx];
            y=y+diry[diridx];
        }
        return ans;
    }
};
