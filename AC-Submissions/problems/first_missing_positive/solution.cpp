class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            while(nums[i]>0&&nums[i]<len&&nums[i]<(i+1)&&(nums[i]!=nums[nums[i]-1]))swap(nums[i],nums[nums[i]-1]);
        }
        int ans=len+1;
        for(int i=0;i<len;i++){
            if(nums[i]!=(i+1)){
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};