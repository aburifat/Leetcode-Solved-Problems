class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int now=len-1;
        for(int i=len-2;i>=0;i--){
            if(nums[i]+i>=now)now=i;
        }
        if(now==0)return true;
        else return false;
    }
};