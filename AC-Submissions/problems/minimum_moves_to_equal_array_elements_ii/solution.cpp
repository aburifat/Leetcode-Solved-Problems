class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len=nums.size();
        vector<long long>sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(i==0)sum.push_back(nums[i]);
            else sum.push_back(nums[i]+sum[i-1]);
        }
        int madian;
        int idx=len/2;
        if(len%2==0){
            madian=nums[idx]+nums[idx-1];
            madian/=2;
        }else{
            madian=nums[idx];
        }
        long long ans=0;
        for(int i=0;i<len;i++){
            if(nums[i]<madian)ans+=(madian-nums[i]);
            else if(nums[i]>madian)ans+=(nums[i]-madian);
        }
        return ans;
    }
};