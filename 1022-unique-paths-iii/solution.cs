public class Solution {
    bool[][] visited;
    private int[] dx = new int[]{0,0,1,-1};
    private int[] dy = new int[]{1,-1,0,0};
    private int solve(int x, int y, int ct, int mx, int n, int m, int[][] grid){
        if(grid[x][y] == 2){
            if(ct == mx) return 1;
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < 4; i++){
            int currX = x + dx[i];
            int currY = y + dy[i];
            if(currX < 0 || currY < 0 || currX >= n || currY >= m || visited[currX][currY] || grid[currX][currY] == -1) continue;
            visited[currX][currY] = true;
            ans += solve(currX,currY,ct+1,mx,n,m,grid);
            visited[currX][currY] = false;
        }
        return ans;
    }
    public int UniquePathsIII(int[][] grid) {
        int n = grid.Length;
        int m = grid[0].Length;
        int cellCount = 0;
        int stx = 0, sty = 0, edx = 0, edy = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0)cellCount++;
                else if(grid[i][j] == 1){
                    stx = i;
                    sty = j;
                }else if(grid[i][j] == 2){
                    edx = i;
                    edy = j;
                }
            }
        }
        visited = new bool[n][];
        for(int i=0;i<n;i++){
            visited[i] = new bool[m];
            for(int j=0;j<m;j++){
                visited[i][j] = false;
            }
        }
        visited[stx][sty] = true;
        int ans = solve(stx,sty,0,cellCount+1,n,m,grid);
        return ans;
    }
}
