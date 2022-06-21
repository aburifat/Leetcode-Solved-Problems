class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>dup=nums;
        sort(nums.begin(),nums.end());
        vector<int>ans;
        map<int,int>mp;
        for(int i=nums.size()-k;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[dup[i]]){
                ans.push_back(dup[i]);
                mp[dup[i]]--;
            }
        }
        return ans;
    }
};