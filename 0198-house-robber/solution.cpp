class Solution {
    int dp[110];
    int solve(int idx,vector<int>& nums){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        return dp[idx] = max(solve(idx+1,nums),nums[idx]+solve(idx+2,nums));
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};
