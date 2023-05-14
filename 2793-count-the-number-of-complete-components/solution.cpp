class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>visited;
    void dfs(int s,vector<int>& v){
        visited[s]=true;
        v.push_back(s);
        for(int i=0;i<(int)adj[s].size();i++){
            int u=adj[s][i];
            if(!visited[u]){
                dfs(u,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n+5,vector<int>());
        visited.assign(n+5,false);
        int len=edges.size();
        for(int i=0;i<len;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>>comp;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int>v;
                dfs(i,v);
                comp.push_back(v);
            }
        }
        int ans=0;
        for(int i=0;i<(int)comp.size();i++){
            int edge=comp[i].size()-1;
            bool ck=true;
            for(int j=0;j<(int)comp[i].size();j++){
                int u=comp[i][j];
                if((int)adj[u].size()!=edge){
                    ck=false;
                    break;
                }
            }
            if(ck==true)ans++;
        }
        return ans;
    }
};
