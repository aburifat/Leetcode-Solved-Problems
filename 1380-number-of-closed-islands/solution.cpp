#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> >adj;
map<pair<ll,ll>,bool>visited;

ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};

void digLand(ll x,ll y,ll n, ll m){
    queue<pair<ll,ll>>q;
    q.push({x,y});
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        visited[{x,y}]=true;
        adj[x][y]=1;
        for(ll i=0;i<4;i++){
            ll u=x+dx[i];
            ll v=y+dy[i];
            if(u>=0&&v>=0&&u<n&&v<m){
                if(!visited[{u,v}]&&!adj[u][v]){
                    visited[{u,v}]=true;
                    q.push({u,v});
                }
            }
        }
    }
}

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        adj=grid;
        visited.clear();
        ll n=adj.size();
        ll m=0;
        if(n>0)m=adj[0].size();
        for(ll i=0;i<m;i++){
            if(!visited[{0,i}]&&!adj[0][i]){
                digLand(0,i,n,m);
            }
            if(!visited[{n-1,i}]&&!adj[n-1][i]){
                digLand(n-1,i,n,m);
            }
        }
        for(ll i=0;i<n;i++){
            if(!visited[{i,0}]&&!adj[i][0]){
                digLand(i,0,n,m);
            }
            if(!visited[{i,m-1}]&&!adj[i][m-1]){
                digLand(i,m-1,n,m);
            }
        }
        ll ct=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(!visited[{i,j}]&&!adj[i][j]){
                    digLand(i,j,n,m);
                    ct++;
                }
            }
        }
        return ct;
    }
};
