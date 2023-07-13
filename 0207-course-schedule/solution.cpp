class Solution {
    vector<vector<int>>adj;
    vector<int>color;
    bool ck = true;
    void dfs(int v){
        color[v]=1;
        for(auto u:adj[v]){
            if(color[u]==0)dfs(u);
            else if(color[u]==1){
                ck=false;
                return;
            }
        }
        color[v]=2;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        adj.assign(n,vector<int>());
        color.assign(n,0);
        for(int i=0;i<(int)pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<n;i++){
            if(color[i]==0)
                dfs(i);
                if(!ck)break;
        }
        return ck;
    }
};
