class Solution {
public:
    vector<vector<int>>adj,rev;
    vector<int>indeg,outdeg;
    vector<bool>visited;
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.assign(n+5,vector<int>(0));
        rev.assign(n+5,vector<int>(0));
        indeg.assign(n+5,0);
        outdeg.assign(n+5,0);
        visited.assign(n+5,false);
        for(int i=0;i<n-1;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            rev[v].push_back(u);
            indeg[v]++;
            outdeg[u]++;
        }
        int ct=0;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int s=q.front();
            q.pop();
            for(int i=0;i<rev[s].size();i++){
                int u=rev[s][i];
                if(!visited[u]){
                    visited[u]=true;
                    q.push(u);
                }
            }
            for(int i=0;i<adj[s].size();i++){
                int u=adj[s][i];
                if(!visited[u]){
                    ct++;
                    visited[u]=true;
                    q.push(u);
                }
            }
        }
        return ct;
    }
};