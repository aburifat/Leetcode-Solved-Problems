class Solution {
public:
    void getSubset(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& ans){
        if(idx>=(int)nums.size()){
            ans.push_back(curr);
            return;
        }
        getSubset(nums,idx+1,curr,ans);
        curr.push_back(nums[idx]);
        getSubset(nums,idx+1,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        getSubset(nums,0,curr,ans);
        return ans;
    }
};
