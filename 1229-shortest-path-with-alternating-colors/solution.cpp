class Solution {
public:
    vector<int>red[105],blue[105];
    bool visited[105][2];
    int dis[105];
    queue<pair<pair<int,int>,bool>>q;

    void bfs(int s){
        dis[s]=0;
        while(!q.empty())q.pop();
        q.push({{s,0},true});
        q.push({{s,0},false});
        while(!q.empty()){
            s=q.front().first.first;
            int d=q.front().first.second;
            bool ck=q.front().second;
            q.pop();
            auto v=(ck)?red[s]:blue[s];
            for(auto u:v){
                if(!visited[u][ck]){
                    visited[u][ck]=true;
                    if(dis[u]==-1)dis[u]=d+1;
                    else dis[u]=min(dis[u],d+1);
                    q.push({{u,d+1},!ck});
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for(int i=0;i<n;i++)dis[i]=-1;
        for(int i=0;i<(int)redEdges.size();i++){
            int u,v;
            u=redEdges[i][0];
            v=redEdges[i][1];
            red[u].push_back(v);
        }
        for(int i=0;i<(int)blueEdges.size();i++){
            int u,v;
            u=blueEdges[i][0];
            v=blueEdges[i][1];
            blue[u].push_back(v);
        }
        bfs(0);
        vector<int>ans;
        for(int i=0;i<n;i++)ans.push_back(dis[i]);
        return ans;
    }
};
