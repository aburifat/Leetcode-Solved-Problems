public class Solution {
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};
    int[][] dis;
    void bfs(int[][] grid, int n, int x, int y){
        Queue<(int,int,int)>q = new Queue<(int,int,int)>();
        q.Enqueue((x,y,0));
        while(q.Count!=0){
            var tmp = q.Dequeue();
            x = tmp.Item1;
            y = tmp.Item2;
            int d = tmp.Item3;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=n)continue;
                if(dis[nx][ny]==-1||dis[nx][ny]>d+1){
                    dis[nx][ny]=d+1;
                    q.Enqueue((nx,ny,d+1));
                }
            }
        }
    }
    public int MaxDistance(int[][] grid) {
        int n=grid.Length;
        dis = new int[n][];
        for(int i=0;i<n;i++){
            dis[i] = new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)dis[i][j]=0;
                else dis[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(grid,n,i,j);
                }
            }
        }
        int mx_dis = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)mx_dis=Math.Max(mx_dis,dis[i][j]);
            }
        }
        return mx_dis;
    }
}
