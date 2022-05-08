#include<bits/stdc++.h>
using namespace std;
typedef int ll;

vector<vector<ll> > adj;
map<pair<ll,ll>,ll> visited;
vector<pair<ll,ll>>border;

ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};

void bfs(ll sr, ll sc, ll n, ll m){
    queue<pair<ll,ll> >q;
    q.push({sr,sc});
    visited[{sr,sc}]=true;
    ll old_color=adj[sr][sc];
    while(!q.empty()){
        sr=q.front().first;
        sc=q.front().second;
        q.pop();
        ll ct=0;
        for(ll i=0;i<4;i++){
            ll u=sr+dx[i];
            ll v=sc+dy[i];
            if(u<0||v<0||u>=n||v>=m)ct++;
            else if(adj[u][v]!=old_color)ct++;
            else{
                if(!visited[{u,v}]){
                    visited[{u,v}]=true;
                    q.push({u,v});
                }
            }
        }
        if(ct)border.push_back({sr,sc});
    }
}

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        visited.clear();
        border.clear();
        adj=grid;
        ll n=adj.size();
        ll m=0;
        if(n>0)m=adj[0].size();
        bfs(row,col,n,m);
        ll len=border.size();
        for(ll i=0;i<len;i++){
            ll sr=border[i].first;
            ll sc=border[i].second;
            adj[sr][sc]=color;
        }
        return adj;
    }
};