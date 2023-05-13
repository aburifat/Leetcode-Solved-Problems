class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        int ans=0;
        for(int j=0;j<m;j++){
            int mx=0;
            for(int i=0;i<n;i++){
                mx=max(nums[i][j],mx);
            }
            ans+=mx;
        }
        return ans;
    }
};
