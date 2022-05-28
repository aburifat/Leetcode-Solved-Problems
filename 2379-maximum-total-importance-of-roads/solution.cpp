class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>adj(n,0);
        long long len=roads.size();
        for(long long i=0;i<len;i++){
            long long u=roads[i][0];
            long long v=roads[i][1];
            adj[u]++;
            adj[v]++;
        }
        sort(adj.begin(),adj.end());
        long long num=n;
        long long ans=0;
        for(long long i=n-1;i>=0;i--){
            ans+=(num*adj[i]);
            num--;
        }
        return ans;
    }
};
