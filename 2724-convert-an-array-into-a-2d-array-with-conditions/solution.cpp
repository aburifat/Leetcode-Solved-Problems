class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int len = nums.size();
        int ct[201];
        memset(ct,0,sizeof(ct));
        int mx = 0;
        for(int i=0;i<len;i++){
            ct[nums[i]]++;
            mx=max(mx, ct[nums[i]]);
        }
        vector<vector<int>>ans(mx,vector<int>());
        for(int i=1;i<=200;i++){
            int rnk = ct[i];
            for(int j = 0;j<rnk; j++){
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};
