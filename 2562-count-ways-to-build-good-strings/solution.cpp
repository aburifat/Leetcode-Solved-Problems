typedef long long ll;
class Solution {
public:
    ll mod = 1e9+7;
    vector<ll>mem;
    ll dp(int idx, int& zero, int& one){
        if(idx<0)return 0;
        if(idx==0)return 1;
        if(mem[idx]!=-1)return mem[idx];
        mem[idx]=((dp(idx-zero,zero,one)%mod)+(dp(idx-one,zero,one)%mod))%mod;
        return mem[idx];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        mem.assign(high+5,-1);
        ll ans=0;
        for(int i=high;i>=low;i--){
            if(mem[i]==-1)dp(i,zero,one);
            ans=(ans+mem[i])%mod;
        }
        return (int)ans;
    }
};
