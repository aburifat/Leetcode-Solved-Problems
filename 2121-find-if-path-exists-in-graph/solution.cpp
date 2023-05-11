class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>visited;
    bool dfs(int source, int& destination){
        visited[source]=true;
        if(source==destination)return true;
        bool ck=false;
        for(int i=0;i<(int)adj[source].size();i++){
            int u=adj[source][i];
            if(!visited[u])ck|=dfs(u,destination);
        }
        return ck;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.assign(n+5,vector<int>());
        visited.assign(n+5,false);
        int len = edges.size();
        for(int i=0; i<len ; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(source,destination);
    }
};
