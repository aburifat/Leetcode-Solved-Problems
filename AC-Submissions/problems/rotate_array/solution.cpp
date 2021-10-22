class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        vector<int>v;
        k=k%len;
        for(int i=len-k;i<len;i++)v.push_back(nums[i]);
        for(int i=0;i<(len-k);i++)v.push_back(nums[i]);
        nums=v;
    }
};