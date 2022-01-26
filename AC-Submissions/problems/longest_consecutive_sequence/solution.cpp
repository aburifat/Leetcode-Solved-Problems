#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,ll>parent,siz,visited;

void init(){
    parent.clear();
    siz.clear();
    visited.clear();
}

void make_set(ll v)
{
    parent[v]=v;
    siz[v]=1;
}

ll find_set(ll v)
{
    if(v==parent[v])return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(ll a, ll b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(siz[a]<siz[b])
            swap(a,b);
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        init();
        ll len=nums.size();
        for(ll i=0;i<len;i++){
            ll num=nums[i];
            if(visited[num]==1)continue;
            make_set(num);
            visited[num]=1;
            if(visited[num-1]==1){
                union_sets(num,num-1);
            }
            if(visited[num+1]==1){
                union_sets(num,num+1);
            }
        }
        ll ans=0;
        for(ll i=0;i<len;i++){
            ll pr=find_set(nums[i]);
            ans=max(ans,siz[pr]);
        }
        return ans;
    }
};
