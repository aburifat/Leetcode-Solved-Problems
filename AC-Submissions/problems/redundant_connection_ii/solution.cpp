class Solution {
    vector<vector<int>>adj,parent;
    vector<bool>visited;
    map<pair<int,int>,int>edgeRank;
public:
    void init(int n){
        adj.assign(n+3,vector<int>());
        visited.assign(n+5,false);
        parent.assign(n+5,vector<int>());
        edgeRank.clear();
    }
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        init(n);
        int manyIn=0;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            parent[v].push_back(u);
            edgeRank[{u,v}]=i+1;
            if((int)parent[v].size()>1){
                manyIn=v;
            }
        }
        vector<pair<int,int>>ans;
        if(manyIn!=0){
            int root=1;
            for(int i=1;i<=n;i++){
                if((int)parent[i].size()==0){
                    root=i;
                    break;
                }
            }
            for(int i=0;i<(int)parent[manyIn].size();i++){
                int u=parent[manyIn][i];
                int pos=0;
                for(int i=0;i<(int)adj[u].size();i++){
                    if(adj[u][i]==manyIn){
                        pos=i;
                        break;
                    }
                }
                adj[u].erase(adj[u].begin()+pos);
                visited.assign(n+5,false);
                bfs(root);
                bool isTree=true;
                for(int i=1;i<=n;i++){
                    if(visited[i]==false){
                        isTree=false;
                        break;
                    }
                }
                if(isTree)ans.push_back({u,manyIn});
                adj[u].push_back(manyIn);
            }
        }else{
            for(int i=1;i<=n;i++){
                int root=i;
                for(int i=0;i<(int)parent[root].size();i++){
                    int u=parent[root][i];
                    int pos=0;
                    for(int i=0;i<(int)adj[u].size();i++){
                        if(adj[u][i]==root){
                            pos=i;
                            break;
                        }
                    }
                    adj[u].erase(adj[u].begin()+pos);
                    visited.assign(n+5,false);
                    bfs(root);
                    bool isTree=true;
                    for(int i=1;i<=n;i++){
                        if(visited[i]==false){
                            isTree=false;
                            break;
                        }
                    }
                    if(isTree){
                        ans.push_back({u,root});
                    }
                    adj[u].push_back(root);
                }
            }
        }
        pair<int,int>pr={-1,-1};
        int rnk=-1;
        for(int i=0;i<(int)ans.size();i++){
            if(rnk<edgeRank[{ans[i].first,ans[i].second}]){
                rnk=edgeRank[{ans[i].first,ans[i].second}];
                pr=ans[i];
            }
        }
        vector<int>go;
        go.push_back(pr.first);
        go.push_back(pr.second);
        return go;
    }
};