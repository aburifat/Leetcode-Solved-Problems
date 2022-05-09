#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto arr=nums;
        vector<int>ans;
        ll len=arr.size();
        map<ll,ll>mp;
        for(ll i=0;i<len;i++){
            ll val=target-arr[i];
            if(mp[val]){
                ans.push_back(mp[val]-1);
                ans.push_back(i);
                return ans;
            }else mp[arr[i]]=i+1;
        }
        return ans;
    }
};
