class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int len = nums.size();
        int start = 0, mnidx=-1, mxidx = -1;
        long long ans = 0;
        for(int i=0;i<len;i++){
            if(nums[i]<minK||nums[i]>maxK){
                start=i+1;
                mnidx=-1;
                mxidx=-1;
            }
            if(nums[i]==minK){
                mnidx=i;
            }
            if(nums[i]==maxK){
                mxidx=i;
            }
            if(mnidx!=-1&&mxidx!=-1){
                ans += (min(mnidx,mxidx)-start+1);
            }
        }
        return ans;
    }
};
