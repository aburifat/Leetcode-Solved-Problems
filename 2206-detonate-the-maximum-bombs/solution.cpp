class Solution {
public:
    long long sq(long long num){
        return num*num;
    }
    bool inRange(int i, int j,  vector<vector<int>>& bombs){
        long long x1=bombs[i][0];
        long long x2=bombs[j][0];
        long long y1=bombs[i][1];
        long long y2=bombs[j][1];
        long long rad = bombs[i][2];
        long long dis1 = sq(bombs[i][0]-bombs[j][0]) + sq(bombs[i][1]-bombs[j][1]);
        long long dis2 = sq(rad);
        if(dis1<=dis2)return true;
        return false;
    }
    vector<vector<int>>adj;
    vector<bool>visited;

    int dfs(int idx, vector<vector<int>>& bombs){
        visited[idx]=true;
        int ct = 1;
        for(int i=0;i<(int)adj[idx].size();i++){
            int nxt=adj[idx][i];
            if(!visited[nxt]){
                ct+=dfs(nxt,bombs);
            }
        }
        return ct;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int len = bombs.size();
        adj.assign(len,vector<int>());
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i==j)continue;
                if(inRange(i,j,bombs)){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<len;i++){
            visited.assign(len,false);
            ans=max(ans,dfs(i,bombs));
        }
        return ans;
    }
};
