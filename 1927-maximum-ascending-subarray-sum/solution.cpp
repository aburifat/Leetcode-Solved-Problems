class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int len=nums.size();
        int right[len+5];
        int ans=0;
        for(int i=len-1;i>=0;i--){
            if(i==len-1)right[i]=nums[len-1];
            else{
                if(nums[i]<nums[i+1]){
                    right[i]=nums[i]+right[i+1];
                }else right[i]=nums[i];
            }
            ans=max(ans,right[i]);
        }
        return ans;
    }
};
