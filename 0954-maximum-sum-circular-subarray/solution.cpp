class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len=nums.size();
        int mxSum=INT_MIN;
        int mnSum=INT_MAX;
        int currMax=nums[0];
        int currMin=nums[0];
        int totalSum=nums[0];
        int mxVal=nums[0];
        for(int i=1;i<len;i++){
            currMax=max(nums[i],currMax+nums[i]);
            mxSum=max(mxSum,currMax);
            currMin=min(nums[i],currMin+nums[i]);
            mnSum=min(mnSum,currMin);
            totalSum+=nums[i];
            mxVal=max(mxVal,nums[i]);
        }
        return (mxVal<0)? mxVal:max(mxSum,totalSum-mnSum);
    }
};
