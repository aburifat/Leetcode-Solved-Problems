class Solution {
    int dgtCt(int n){
        if(n<2)return 0;
        int ct = 0;
        while(n){
            n/=10;
            ct++;
        }
        return ct;
    }
public:
    int dp[110][110]; //states: s.size(), k

    int goBabe(string s, int idx, int n, int k){
        if(n-idx <= k) return 0; //deleted all
        if(dp[idx][k]!=-1)return dp[idx][k];

        int val = INT_MAX;
        if(k!=0)val = goBabe(s, idx+1, n, k-1); // will delete the current

        // will keep the current and minimize later digits
        int cnt = 1;
        int toDelete = k;
        for(int i = idx+1; i<=n && toDelete>=0; i++){
            val = min(val, goBabe(s,i,n,toDelete) + 1 + dgtCt(cnt));
            if(i==n)break;
            if(s[i]==s[idx])cnt++;
            else toDelete--;
        }
        return dp[idx][k] = val;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int ans = goBabe(s,0,n,k);
        return ans;
    }
};
