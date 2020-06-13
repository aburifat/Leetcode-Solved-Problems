class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int len=nums.size();
        len/=2;
        vector<int>ans;
        for(int i=0;i<len;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+len]);
        }
        return ans;
    }
};
