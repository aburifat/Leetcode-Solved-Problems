class Solution {
    map<int,int>parent,siz;
public:
    void init(){
        parent.clear();
        siz.clear();
    }
    void make_set(int v){
        parent[v]=v;
        siz[v]=1;
    }
    int find_set(int v){
        if(v==parent[v])return v;
        return parent[v]=find_set(parent[v]);
    }
    void union_sets(int u, int v){
        u=find_set(u);
        v=find_set(v);
        if(u!=v){
            if(siz[u]<siz[v]){
                swap(u,v);
            }
            parent[v]=u;
            siz[u]+=siz[v];
        }
    }
    bool ck_connect(int u, int v){
        u=find_set(u);
        v=find_set(v);
        if(u!=v)return false;
        else return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        int n=edges.size();
        vector<int>ans;
        for(int i=1;i<=n;i++)make_set(i);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(!ck_connect(u,v)){
                union_sets(u,v);
            }else{
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
        }
        return ans;
    }
};
