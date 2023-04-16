typedef long long ll;
class Solution {
    vector<vector<ll>>charBank;
    vector<vector<ll>>dp;
    ll mod=1e9+7;
    void init(ll m, ll len){
        charBank.assign(m,vector<ll>(26,0));
        dp.assign(m,vector<ll>(len,-1));
    }
    ll ctDP(ll k, ll idx, ll& m, ll& len, string& target){
        if(idx>=len)return 1;
        if(k>=m)return 0;
        if(dp[k][idx]!=-1)return dp[k][idx];
        ll val = ctDP(k+1,idx,m,len,target);
        ll tmp=target[idx]-'a';
        if(charBank[k][tmp]>0){
            ll val2=ctDP(k+1,idx+1,m,len,target);
            val=(val+(charBank[k][tmp]*(val2%mod))%mod)%mod;
        }
        dp[k][idx]=val;
        return dp[k][idx];
    }
public:
    int numWays(vector<string>& words, string target) {
        ll n=words.size();
        ll m=words[0].size();
        ll len=target.size();
        init(m,len);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                ll tmp = words[i][j]-'a';
                charBank[j][tmp]++;
            }
        }
        ll ans=ctDP(0,0,m,len,target);
        return (int)ans;
    }
};
