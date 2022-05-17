class Solution {
    vector<vector<int>>adj;
    vector<bool>visited;
public:
    void bfs(int s){
        queue<int>q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            s=q.front();
            q.pop();
            for(int i=0;i<(int)adj[s].size();i++){
                int u=adj[s][i];
                if(!visited[u]){
                    visited[u]=true;
                    q.push(u);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        adj.assign(n+5,vector<int>());
        visited.assign(n+5,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(isConnected[i][j]==1)adj[i].push_back(j);
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ct++;
                bfs(i);
            }
        }
        return ct;
    }
};