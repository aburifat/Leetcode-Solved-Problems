#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

map<pair<int,int>,int>visited;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs(vector<vector<int>>adj, int sr, int sc, int n, int m){
    queue<pair<int,int>>q;
    q.push({sr,sc});
    visited[{sr,sc}]=true;
    int area=0;
    while(!q.empty()){
        sr=q.front().first;
        sc=q.front().second;
        q.pop();
        area++;
        for(int i=0;i<4;i++){
            int u=sr+dx[i];
            int v=sc+dy[i];
            if(u>=0&&v>=0&&u<n&&v<m){
                if(!visited[{u,v}]&&adj[u][v]==1){
                    visited[{u,v}]=true;
                    q.push({u,v});
                }
            }
        }
    }
    return area;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>adj=grid;
        visited.clear();
        int n=adj.size();
        int m=0;
        if(n!=0)m=adj[0].size();
        int mx_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(adj[i][j]==1&&!visited[{i,j}]){
                    int area=bfs(adj,i,j,n,m);
                    mx_area=max(mx_area,area);
                }
            }
        }
        return mx_area;
    }
};
