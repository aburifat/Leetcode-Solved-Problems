class Solution {
public:
    void getAns(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0||idx>=candidates.size())return;
        for(int i=idx;i<candidates.size();i++){
            if(i>idx&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            curr.push_back(candidates[i]);
            getAns(candidates,target-candidates[i],i+1,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        getAns(candidates, target, 0, curr, ans);
        return ans;
    }
};
