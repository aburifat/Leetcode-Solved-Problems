#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,bool>visited;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> adj=grid;
        visited.clear();
        queue<pair<int,int> >q;
        int n=adj.size();
        int m=0;
        int ans=0;
        if(n!=0)m=adj[0].size();
        for(int i=0;i<n;i++){
            int ck=0;
            for(int j=0;j<m;j++){
                if(adj[i][j]==1){
                    ck=1;
                    q.push({i,j});
                    break;
                }
            }
            if(ck)break;
        }
        while(!q.empty()){
            int sr=q.front().first;
            int sc=q.front().second;
            q.pop();
            visited[{sr,sc}]=true;
            int ct=0;
            for(int i=0;i<4;i++){
                int u=sr+dx[i];
                int v=sc+dy[i];
                if(u<0||v<0||u>=n||v>=m)ct++;
                else if(adj[u][v]==0)ct++;
                else{
                    if(!visited[{u,v}]){
                        visited[{u,v}]=true;
                        q.push({u,v});
                    }
                }
            }
            ans+=ct;
        }
        return ans;
    }
};