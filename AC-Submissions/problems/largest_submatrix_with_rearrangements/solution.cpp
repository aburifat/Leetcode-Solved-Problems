#include<bits/stdc++.h>
using namespace std;
typedef int ll;

vector<vector<ll>>adj;

ll largestRectangleHistogram(vector<ll>v,ll n){
    vector<ll>right(n+5),left(n+5);
    stack<ll>st;
    for(ll i=0;i<n;i++){
        while(!st.empty()){
            if(v[st.top()]>=v[i])st.pop();
            else break;
        }
        if(st.empty())left[i]=0;
        else left[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(ll i=n-1;i>=-0;i--){
        while(!st.empty()){
            if(v[st.top()]>=v[i])st.pop();
            else break;
        }
        if(st.empty())right[i]=n-1;
        else right[i]=st.top()-1;
        st.push(i);
    }
    ll val=0;
    for(ll i=0;i<n;i++){
        ll tmp=abs(right[i]-left[i])+1;
        tmp*=v[i];
        val=max(val,tmp);
    }
    return val;
}

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        adj=matrix;
        ll n=matrix.size();
        ll m=0;
        if(n>0)m=matrix[0].size();
        for(ll i=1;i<n;i++){
            for(ll j=0;j<m;j++){
                if(adj[i][j]!=0)adj[i][j]+=adj[i-1][j];
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            vector<ll>v;
            for(ll j=0;j<m;j++){
                v.push_back(adj[i][j]);
            }
            sort(v.begin(),v.end());
            ll val=largestRectangleHistogram(v,m);
            ans=max(ans,val);
        }
        return ans;
    }
};