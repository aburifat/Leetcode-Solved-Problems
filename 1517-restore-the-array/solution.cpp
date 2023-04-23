class Solution {
    long long MOD = 1e9+7;
    vector<long long>dp;
    long long ctDP(int idx, int len, string& s, int k){
        if(idx>=len)return 1;
        if(dp[idx]!=-1)return dp[idx];
        long long ct=0;
        long long val=0;
        for(int i=idx;i<len;i++){
            val*=10;
            val+=(s[i]-'0');
            if(val==0)break;
            if(val<=k){
                ct+=ctDP(i+1,len,s,k);
                ct%=MOD;
            }else break;
        }
        return dp[idx]=ct;
    }
public:
    int numberOfArrays(string s, int k) {
        int len = s.size();
        dp.assign(len,-1);
        long long ans = ctDP(0,len,s,k);
        return (int)ans;
    }
};
