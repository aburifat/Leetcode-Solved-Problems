class Solution {
    vector<bool>visited,color;
public:
    bool dfs(int s, bool col, vector<vector<int>>& graph){
        visited[s]=true;
        color[s]=col;
        col=!col;
        bool ck=true;
        for(int i=0;i<(int)graph[s].size();i++){
            int u=graph[s][i];
            if(visited[u]&&color[u]!=col)return false;
            else if(!visited[u]) ck&=dfs(u,col,graph);
        }
        return ck;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int len=graph.size();
        visited.assign(len,false);
        color.assign(len,false);
        for(int i=0;i<len;i++){
            if(!visited[i]){
                if(!dfs(i,true,graph))return false;
            }
        }
        return true;
    }
};
