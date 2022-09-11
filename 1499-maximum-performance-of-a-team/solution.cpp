typedef long long ll;
#define F first
#define S second

constexpr ll mod=1e9+7;

const bool cmp(pair<ll,ll>a, pair<ll,ll>b){
    if(a.S==b.S){
        return a.F>b.F;
    }return a.S>b.S;
}


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll,ll>>v;
        for(ll i=0;i<n;i++){
            v.push_back({speed[i],efficiency[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(ll i=0;i<n;i++){
            //cout<<v[i].F<<" "<<v[i].S<<endl;
        }
        ll ans=0;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll ct=0;
        ll sum=0;
        for(ll i=0;i<n;i++){
            if(ct==k){
                ct--;
                sum-=pq.top();
                pq.pop();
            }
            pq.push(v[i].F);
            sum+=v[i].F;
            ct++;
            ans=max(ans,sum*v[i].S);
        }
        ans%=mod;
        return (int)ans;
    }
};
