class Solution {
public:
    int dp[110];
    int ctDp(vector<int>& nums, int idx){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int val1=ctDp(nums,idx+1);
        int val2=nums[idx]+ctDp(nums,idx+2);
        dp[idx]=max(val1,val2);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        for(int i=0;i<110;i++)dp[i]=-1;
        int ans=ctDp(nums,0);
        if(nums.size()>1)ans=max(ans,ctDp(nums,1));
        return ans;
    }
};
