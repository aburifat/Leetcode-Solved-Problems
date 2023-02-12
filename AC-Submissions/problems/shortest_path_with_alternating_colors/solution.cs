public class Solution {
    List<int>[] red;
    List<int>[] blue;
    bool[][] visited;
    int[] dis;
    Queue<Tuple<int,int,bool>>q = new Queue<Tuple<int,int,bool>>();

    void bfs(int s){
        dis[s]=0;
        visited[s][0]=true;
        visited[s][1]=true;
        q.Enqueue(Tuple.Create(s,0,true));
        q.Enqueue(Tuple.Create(s,0,false));
        while(q.Count!=0){
            s=q.Peek().Item1;
            int d = q.Peek().Item2;
            bool ck = q.Peek().Item3;
            int ck_int = (ck==true)?1:0;
            q.Dequeue();
            List<int> v = new List<int>();
            v=(ck==true)?red[s]:blue[s];
            foreach(int u in v){
                if(visited[u][ck_int]==false){
                    visited[u][ck_int]=true;
                    if(dis[u]==-1)dis[u]=d+1;
                    else dis[u]=Math.Min(dis[u],d+1);
                    q.Enqueue(Tuple.Create(u,d+1,!ck));
                }
            }
        }
    }
    public int[] ShortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        red = new List<int>[n];
        blue = new List<int>[n];
        visited = new bool[n][];
        dis = new int[n];
        for(int i=0;i<n;i++){
            visited[i]=new bool[2];
            red[i]=new List<int>();
            blue[i]=new List<int>();
            dis[i]=-1;
        }
        for(int i=0;i<redEdges.Length;i++){
            int u,v;
            u=redEdges[i][0];
            v=redEdges[i][1];
            red[u].Add(v);
        }
        for(int i=0;i<blueEdges.Length;i++){
            int u,v;
            u=blueEdges[i][0];
            v=blueEdges[i][1];
            blue[u].Add(v);
        }
        bfs(0);
        return dis;

    }
}