class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<(int)nums.size();i++){
            sum+=nums[i];
            sum-=i;
        }
        sum-=(int)nums.size();
        sum=-sum;
        return sum;
    }
};
