class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int sum=nums[0];
        int tmp=0;
        for(int i=0;i<len;i++){
            tmp+=nums[i];
            if(tmp<0){
                tmp=0;
                sum=max(sum,nums[i]);
                continue;
            }
            sum=max(sum,tmp);
        }
        return sum;
    }
};