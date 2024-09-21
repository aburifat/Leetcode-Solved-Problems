class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0;
        int ct = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > mx) {
                ans = 0;
                mx = nums[i];
                ct = 1;
            }
            else if(nums[i] == mx) {
                ct++;
            }
            else {
                if(ct > ans) ans = ct;
                ct = 0;
            }
        }
        return ct > ans ? ct : ans;
    }
};
