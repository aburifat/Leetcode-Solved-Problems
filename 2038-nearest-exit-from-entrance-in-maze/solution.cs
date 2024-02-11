public class Solution {
    private int[] dx = new int[]{1,-1,0,0};
    private int[] dy = new int[]{0,0,1,-1};
    public int NearestExit(char[][] maze, int[] entrance) {
        Queue<(int,int,int)>q = new Queue<(int,int,int)>();
        int n = maze.Length;
        int m = maze[0].Length;
        int stx = entrance[0];
        int sty = entrance[1];
        bool[,] visited = new bool[n,m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i,j] = false;
            }
        }
        int ans = -1;
        visited[stx,sty] = true;
        q.Enqueue((stx,sty,0));
        while(q.Count != 0){
            (int x, int y, int dis) = q.Dequeue();
            if(x == 0 || y == 0 || x == n-1 || y == m-1){
                if(!(x == stx && y == sty)){
                    ans = dis;
                    break;
                }
            }
            for(int i = 0; i < 4; i++){
                int currX = x + dx[i];
                int currY = y + dy[i];
                if(currX < 0 || currX >= n || currY < 0 || currY >= m)continue;
                if(maze[currX][currY] == '.' && !visited[currX, currY]){
                    visited[currX,currY] = true;
                    q.Enqueue((currX, currY, dis+1));
                }
            }
        }
        return ans;
    }
}
