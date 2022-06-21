class Solution {
public:
    static bool cmp(pair<string,int>& a, pair<string,int>& b){
        if(a.first==b.first)return (a.second>b.second);
        if(a.first.size()==b.first.size()){
            for(int i=0;i<a.first.size();i++){
                if(a.first[i]==b.first[i])continue;
                else{
                    return (a.first[i]>b.first[i]);
                }
            }
        }
        return (a.first.size()>b.first.size());
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        vector<pair<string,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        return v[k-1].first;
    }
};