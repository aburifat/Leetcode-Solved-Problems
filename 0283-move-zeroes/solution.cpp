class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>v;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]!=0)v.push_back(nums[i]);
        }
        int dd=v.size();
        for(int i=dd;i<len;i++){
            v.push_back(0);
        }
        nums=v;
    }
};
