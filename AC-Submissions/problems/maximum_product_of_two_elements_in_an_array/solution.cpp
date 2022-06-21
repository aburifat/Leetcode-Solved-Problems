class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int ans=nums[len-1]-1;
        ans*=(nums[len-2]-1);
        return ans;
    }
};