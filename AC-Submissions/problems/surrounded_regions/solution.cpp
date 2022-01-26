#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<ll,ll>,pair<ll,ll> >parent;
map<pair<ll,ll>,ll>siz;
vector<vector<char> > ans;
ll n,m;

void init(){
    parent.clear();
    siz.clear();
    ans.clear();
}

void make_set(pair<ll,ll>v){
    parent[v]=v;
    siz[v]=1;
}

pair<ll,ll> find_set(pair<ll,ll>v){
    if((parent[v]==v))return v;
    return parent[v]=find_set(parent[v]);
}

void union_set(pair<ll,ll>a, pair<ll,ll>b){
    a=parent[a];
    b=parent[b];
    if(a!=b){
        if(siz[a]<siz[b]){
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

void go_baby(ll a, ll b){
    for(ll i=0;i<4;i++){
        ll x=a+dx[i];
        ll y=b+dy[i];
        if((x>=0)&&(y>=0)&&(x<n)&&(y<m)){
            if(ans[x][y]=='O'){
                ans[x][y]='#';
                make_set({x,y});
                union_set({a,b},{x,y});
                go_baby(x,y);
            }
        }
    }
}

void init_go(ll a, ll b){
    ans[a][b]='#';
    make_set({a,b});
    go_baby(a,b);
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        init();
        ans=board;
        n=board.size();
        m=board[0].size();
        
        ll idx[]={0,m-1};
        for(ll i=0;i<n;i++){
            for(ll j=0;j<2;j++){
                if(ans[i][idx[j]]=='O'){
                    init_go(i,idx[j]);
                }
            }
        }
        
        idx[1]=n-1;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<2;j++){
                if(ans[idx[j]][i]=='O'){
                    init_go(idx[j],i);
                }
            }
        }
        
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(ans[i][j]!='#')ans[i][j]='X';
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(ans[i][j]!='X')ans[i][j]='O';
            }
        }
        board=ans;
    }
};