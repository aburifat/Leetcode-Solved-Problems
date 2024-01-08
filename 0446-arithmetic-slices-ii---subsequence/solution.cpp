class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,long long>,int>mp;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long dif = (long long)nums[j] - (long long)nums[i];
                ans += mp[{i,dif}];
                mp[{j,dif}] += (mp[{i,dif}] + 1);
            }
        }
        return ans;
    }
};
