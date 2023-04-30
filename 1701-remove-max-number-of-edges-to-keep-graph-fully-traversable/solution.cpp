class Solution {
    vector<vector<int>>adj;
    vector<bool>visited;
    static bool cmp(vector<int>a,vector<int>b){
        if(a[0]==b[0]){
            if(a[1]==b[1]){
                return a[2]<b[2];
            }
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    int dfs(int s){
        visited[s]=true;
        int ct=1;
        for(auto u:adj[s]){
            if(!visited[u]){
                ct+=dfs(u);
            }
        }
        return ct;
    }
    pair<int,int> getCount(int idx, int n, vector<vector<int>>& edges){
        adj.assign(n+5,vector<int>());
        visited.assign(n+5,false);
        for(int i=0;i<(int)edges.size();i++){
            if(edges[i][0]==idx||edges[i][0]==3){
                adj[edges[i][1]].push_back(edges[i][2]);
                adj[edges[i][2]].push_back(edges[i][1]);
            }
        }
        int frac=0;
        int edge=0;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                int tmp=dfs(i);
                edge+=(tmp-1);
                frac++;
                if(tmp==1)visited[i]=false;
            }
        }
        return {edge,frac};
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        auto ct=getCount(1,n,edges);
        for(int i=1;i<=n;i++){
            if(!visited[i])return -1;
        }
        ct=getCount(2,n,edges);
        for(int i=1;i<=n;i++){
            if(!visited[i])return -1;
        }
        ct=getCount(3,n,edges);
        int ans=(int)edges.size();
        ans-=ct.first;
        if(ct.second>1){
            ans-=((ct.second-1)*2);
        }
        if(ans<0)ans=-1;
        return ans;
    }
};
