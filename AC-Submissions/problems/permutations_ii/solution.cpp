class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>v=nums;
        vector<vector<int>>ans;
        map<vector<int>,int>mp;
        sort(v.begin(),v.end());
        do{
            if(mp[v]==0){
                mp[v]=1;
                ans.push_back(v);
            }
        }while(next_permutation(v.begin(),v.end()));
        return ans;
    }
};