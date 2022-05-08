#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>adj;
vector<vector<int>>bomb;
map<ll,bool>visited;

ll bfs(ll s){
    visited.clear();
    ll ct=0;
    queue<ll>q;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        visited[s]=true;
        ct++;
        ll len=adj[s].size();
        for(ll i=0;i<len;i++){
            ll u=adj[s][i];
            if(!visited[u]){
                visited[u]=true;
                q.push(u);
            }
        }
    }
    return ct;
}

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        bomb=bombs;
        ll n=bomb.size();
        adj.assign(n+5,vector<ll>(0));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(i==j)continue;
                ll xx=abs(bomb[i][0]-bomb[j][0]);
                xx*=xx;
                ll yy=abs(bomb[i][1]-bomb[j][1]);
                yy*=yy;
                ll dis=xx+yy;
                ll dd=bomb[i][2];
                dd*=dd;
                if(dis<=dd)adj[i].push_back(j);
                dd=bomb[j][2];
                dd*=dd;
                if(dis<=dd)adj[j].push_back(i);
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll val=bfs(i);
            ans=max(ans,val);
        }
        return ans;
    }
};