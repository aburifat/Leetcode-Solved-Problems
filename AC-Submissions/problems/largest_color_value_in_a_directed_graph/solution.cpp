class Solution {
    vector<vector<int>>adj;
    vector<bool>visited;
    vector<int>sorted;
    vector<int>color;
    vector<vector<int>>ct;

    void init(int len){
        adj.assign(len,vector<int>());
        visited.assign(len,false);
        color.assign(len,0);
        ct.assign(len,vector<int>(26,0));
    }

    void sortDfs(int s){
        visited[s]=true;
        for(int v:adj[s]){
            if(!visited[v])sortDfs(v);
        }
        sorted.push_back(s);
    }

    bool cycleDfs(int s){
        color[s]=1;
        for(int v:adj[s]){
            if(color[v]==0&&cycleDfs(v))return true;
            else{
                if(color[v]==2)continue;
                return true;
            }
        }
        color[s]=2;
        return false;
    }

    void dfs(int s, string& colors){
        visited[s]=true;
        for(int v:adj[s]){
            if(!visited[v]){
                dfs(v,colors);
            }
            for(int i=0;i<26;i++){
                ct[s][i]=max(ct[s][i],ct[v][i]);
            }
        }
        int color = colors[s]-'a';
        ct[s][color]++;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int len = colors.size();
        init(len);
        for(int i=0;i<(int)edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        bool ck=false;
        for(int i=0;i<len;i++){
            if(color[i]==0&&cycleDfs(i)){
                ck=true;
                break;
            }
        }
        if(ck)return -1;
        for(int i=0;i<len;i++){
            if(!visited[i])sortDfs(i);
        }
        reverse(sorted.begin(),sorted.end());
        visited.assign(len,false);
        int mx_ct=0;
        for(int i=0;i<(int)sorted.size();i++){
            if(!visited[sorted[i]]){
                dfs(sorted[i],colors);
                for(int j=0;j<26;j++){
                    mx_ct=max(mx_ct,ct[sorted[i]][j]);
                }
            }
        }
        return mx_ct;
    }
};