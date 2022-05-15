class Solution {
    vector<vector<pair<int,int>>>adj;
    int dis[110];
    bool visited[110];
public:
    void dikstra(int s){
        for(int i=0;i<110;i++){
            visited[i]=false;
            dis[i]=INT_MAX;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,s});
        dis[s]=0;
        while(!q.empty()){
            s=q.top().second;
            q.pop();
            if(visited[s])continue;
            visited[s]=true;
            for(int i=0;i<(int)adj[s].size();i++){
                int u=adj[s][i].first;
                int w=adj[s][i].second;
                if(dis[u]>dis[s]+w){
                    dis[u]=dis[s]+w;
                    q.push({dis[u],u});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adj.assign(n+5,vector<pair<int,int>>());
        int e=times.size();
        for(int i=0;i<e;i++){
            int u,v,w;
            u=times[i][0];
            v=times[i][1];
            w=times[i][2];
            adj[u].push_back({v,w});
        }
        dikstra(k);
        int mxDis=-1;
        for(int i=1;i<=n;i++){
            mxDis=max(mxDis,dis[i]);
        }
        if(mxDis==INT_MAX)mxDis=-1;
        return mxDis;
    }
};
