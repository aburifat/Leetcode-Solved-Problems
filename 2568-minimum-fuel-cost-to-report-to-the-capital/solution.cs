public class Solution {
    List<int>[] adj;
    bool[] visited;
    long[] ct;
    long[] cost;
    long k;

    void dfs(int s){
        foreach(var u in adj[s]){
            if(!visited[u]){
                visited[u]=true;
                dfs(u);
                cost[s]+=cost[u];
                ct[s]+=ct[u];
                cost[s]+=(ct[u]/k);
                if(ct[u]%k!=0)cost[s]+=1;
            }
        }
    }

    public long MinimumFuelCost(int[][] roads, int seats) {
        k=seats;
        int n = roads.Length+1;
        adj=new List<int>[n];
        visited = new bool[n];
        ct = new long[n];
        cost = new long[n];
        for(int i=0;i<n;i++){
            adj[i]=new List<int>();
            visited[i]=false;
            ct[i]=1;
            cost[i]=0;
        }
        for(int i=0;i<n-1;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].Add(v);
            adj[v].Add(u);
        }
        visited[0]=true;
        dfs(0);
        return cost[0];
    }
}
