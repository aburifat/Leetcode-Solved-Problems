class Solution {
    int dp[310][1010];
    int goBabe(int idx, int d, vector<int>& v, int n){
        if(idx == n && d == 0)return 0;
        if(idx == n || d == 0 || n < idx + d) return 1e9;
        if(dp[idx][d] != -1) return dp[idx][d];

        int curr_mx = 0, ans = 1e9;
        for(int i = idx; i < n; i++){
            curr_mx = max(curr_mx, v[i]);
            int val = goBabe(i+1,d-1,v,n);
            if(val!=1e9) ans = min(ans,curr_mx+val);
        }
        return dp[idx][d] = ans;
    }
public:
    int minDifficulty(vector<int>& v, int d) {
        int n = v.size();
        if(n<d)return -1;
        memset(dp,-1,sizeof(dp));
        int ans = goBabe(0,d,v,n);
        return ans;
    }
};
