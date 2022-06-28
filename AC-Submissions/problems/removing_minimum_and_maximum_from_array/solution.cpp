class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int len=nums.size();
        int mn=2147483647;
        int mn_idx=-1;
        int mx_idx=-1;
        int mx=-2147483648;
        for(int i=0;i<len;i++){
            if(mn>nums[i]){
                mn=nums[i];
                mn_idx=i;
            }
            if(mx<nums[i]){
                mx=nums[i];
                mx_idx=i;
            }
        }
        int ans=0;
        int l=min(mn_idx,mx_idx);
        int r=max(mn_idx,mx_idx);
        ans=min(r+1,len-l);
        ans=min(ans,l+1+len-r);
        return ans;
    }
};