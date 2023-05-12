class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;

    bool dfs(int s,vector<int>&srt){
        vis[s]=1;
        bool ck=true;
        for(int i=0;i<(int)adj[s].size();i++){
            int u=adj[s][i];
            if(vis[u]==0){
                if(dfs(u,srt)==false){
                    ck=false;
                }
            }else if(vis[u]==1)ck=false;
        }
        vis[s]=2;
        srt.push_back(s);
        return ck;
    }

    pair<bool,vector<int>>srtNode(int k, vector<vector<int>>& c){
        adj.assign(k+5,vector<int>());
        vis.assign(k+5,0);
        for(int i=0;i<(int)c.size();i++){
            adj[c[i][0]].push_back(c[i][1]);
        }
        vector<int>srt;
        bool ck=true;
        for(int i=1;i<=k;i++){
            if(vis[i]==0){
                if(dfs(i,srt)==false)ck=false;
            }
        }
        return {ck,srt};
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<vector<int>>ans;
        auto [ckr,srtr]=srtNode(k,rc);
        auto [ckc,srtc]=srtNode(k,cc);
        if(ckr&ckc){
            ans.assign(k,vector<int>(k,0));
            for(int i=(int)srtr.size()-1;i>=0;i--){
                int key=srtr[i];
                for(int j=(int)srtc.size()-1;j>=0;j--){
                    if(srtc[j]==key){
                        ans[k-i-1][k-j-1]=key;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
