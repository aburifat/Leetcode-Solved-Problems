class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int len=nums.size();
        nums[0]=(nums[0]%k+k)%k;
        for(int i=1;i<len;i++){
            nums[i]+=nums[i-1];
            nums[i]=(nums[i]%k+k)%k;
        }
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<len;i++){
            ans+=mp[nums[i]];
            mp[nums[i]]++;
        }
        for(int i=0;i<len;i++){
            if(nums[i]==0)ans++;
        }
        return ans;
    }
};