class Solution {
    vector<int>parent;
    vector<int>rank;
    vector<int>weight;

    void init(int len){
        rank.assign(len,0);
        weight.assign(len,INT_MAX);
        parent.clear();
        for(int i=0;i<len;i++){
            parent.push_back(i);
        }
    }

    static bool cmp(vector<int>a,vector<int>b){
        return a[2]<b[2];
    }

    int findSet(int u, int limit){
        if(parent[u]==u||weight[u]>=limit)return u;
        else return findSet(parent[u],limit);
    }

    void unionSet(int u, int v, int limit){
        u=findSet(u,INT_MAX);
        v=findSet(v,INT_MAX);
        if(u!=v){
            if(rank[u]>rank[v])swap(u,v);
            if(rank[u]==rank[v])rank[v]++;
            parent[u]=v;
            weight[u]=limit;
        }

    }

    bool isConnected(int u, int v, int limit){
        return findSet(u,limit)==findSet(v,limit);
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<bool>ans;
        init(n);
        sort(edgeList.begin(),edgeList.end(),cmp);
        for(auto edge:edgeList){
            unionSet(edge[0],edge[1],edge[2]);
        }
        for(auto q:queries){
            ans.push_back(isConnected(q[0],q[1],q[2]));
        }
        return ans;
    }
};
