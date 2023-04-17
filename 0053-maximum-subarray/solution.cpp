class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -100000;
        int sum = 0;
        for(int i=0;i<(int)nums.size();i++){
            sum=max(sum+nums[i],nums[i]);
            ans=max(ans,sum);
        }
        return ans;
    }
};
