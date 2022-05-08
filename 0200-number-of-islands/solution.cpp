#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<char>>adj;
map<pair<ll,ll>,ll>visited;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

void bfs(ll sr, ll sc, ll n, ll m){
    queue<pair<ll,ll>>q;
    q.push({sr,sc});
    visited[{sr,sc}]=true;
    while(!q.empty()){
        sr=q.front().first;
        sc=q.front().second;
        q.pop();
        for(ll i=0;i<4;i++){
            ll u=sr+dx[i];
            ll v=sc+dy[i];
            if(u>=0&&v>=0&&u<n&&v<m){
                if(!visited[{u,v}]&&adj[u][v]=='1'){
                    visited[{u,v}]=true;
                    q.push({u,v});
                }
            }
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        visited.clear();
        adj=grid;
        ll n=adj.size();
        ll m=0;
        if(n>0)m=adj[0].size();
        ll ct=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(!visited[{i,j}]&&adj[i][j]=='1'){
                    ct++;
                    bfs(i,j,n,m);
                }
            }
        }
        return ct;
    }
};
