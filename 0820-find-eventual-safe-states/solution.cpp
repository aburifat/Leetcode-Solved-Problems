class Solution {
    vector<vector<int>>adj;
    vector<int>color;
    vector<bool>status;

    void dfs(int v){
        bool ck = true;
        color[v] = 1;
        for(auto u : adj[v]){
            if(color[u]==0){
                dfs(u);
            }
            else if(color[u]==1)ck=false;
            if(!status[u])ck = false;
        }
        color[v]=2;
        status[v] = ck;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        adj = graph;
        int len = adj.size();
        color.assign(len,0);
        status.assign(len,true);
        for(int i=0;i<len;i++){
            if(color[i]==0){
                dfs(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<len;i++){
            if(status[i])ans.push_back(i);
        }
        return ans;
    }
};
