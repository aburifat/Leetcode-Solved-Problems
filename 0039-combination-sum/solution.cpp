class Solution {
public:
    void getAns(vector<int>& nums, int target, vector<int>& curr, int idx, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0||idx>=nums.size())return;
        if(target>=nums[idx]){
            curr.push_back(nums[idx]);
            getAns(nums,target-nums[idx],curr,idx,ans);
            curr.pop_back();
        }
        getAns(nums,target,curr,idx+1,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        getAns(candidates,target,curr,0,ans);
        return ans;
    }
};
