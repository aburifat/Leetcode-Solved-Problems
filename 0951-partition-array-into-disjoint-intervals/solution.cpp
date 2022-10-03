class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int go=0;
        for(int i=0;i<=go;i++){
            go=max(go,v[i].second);
        }
        return go+1;
    }
};
