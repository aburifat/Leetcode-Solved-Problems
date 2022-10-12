class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        while(len>3&&nums[len-2]+nums[len-3]<=nums[len-1]){
            len--;
        }
        int ans=nums[len-1]+nums[len-2]+nums[len-3];
        if(nums[len-2]+nums[len-3]<=nums[len-1])ans=0;
        return ans;
    }
};
