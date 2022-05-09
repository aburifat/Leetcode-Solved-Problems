class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int keys=0;
        pair<int,int>start;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>='a'&&grid[i][j]<='f')keys++;
                if(grid[i][j]=='@'){
                    start.first=i;
                    start.second=j;
                    grid[i][j]='.';
                }
            }
        }
        int bitMask=(1<<keys)-1;
        int mem[n+5][m+5][bitMask+10];
        memset(mem,-1,sizeof mem);
        int ans=INT_MAX;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        queue<pair<pair<int,int>,int>>q;
        q.push({start,0});
        mem[start.first][start.second][0]=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int mask=q.front().second;
            q.pop();
            if(mask==bitMask){
                ans=min(ans,mem[x][y][mask]);
                continue;
            }
            for(int i=0;i<4;i++){
                int u=x+dx[i];
                int v=y+dy[i];
                if(u>=0&&v>=0&&u<n&&v<m){
                    int newMask=mask;
                    if(grid[u][v]=='#')continue;
                    else if(grid[u][v]>='a'&&grid[u][v]<='f'){
                        newMask|=(1<<(grid[u][v]-'a'));
                    }else if(grid[u][v]>='A'&&grid[u][v]<='F'){
                        if((newMask&(1<<(grid[u][v]-'A')))==0)continue;
                    }
                    if((mem[u][v][newMask]==-1)||(mem[u][v][newMask]>mem[x][y][mask]+1)){
                        mem[u][v][newMask]=mem[x][y][mask]+1;
                        q.push({{u,v},newMask});
                    }
                }
            }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
