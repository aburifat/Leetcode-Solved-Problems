class Solution {
public:
    int dp[1010];
    int ctDp(vector<int>& nums, int target){
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int val=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                val+=ctDp(nums,target-nums[i]);
            }
        }
        return dp[target]=val;
    }
    int combinationSum4(vector<int>& nums, int target) {
        for(int i=0;i<1010;i++)dp[i]=-1;
        int ans=ctDp(nums,target);
        return ans;
    }
};