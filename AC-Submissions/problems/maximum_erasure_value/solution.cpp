class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int len=nums.size();
        map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0,j=0;i<len&&j<len;j++){
            if(!mp[nums[j]]){
                mp[nums[j]]++;
                sum+=nums[j];
            }else{
                ans=max(ans,sum);
                while(i<j){
                    if(nums[i]==nums[j]){
                        i++;
                        break;
                    }
                    sum-=nums[i];
                    mp[nums[i]]--;
                    i++;
                }
            }
            if(j==len-1)ans=max(ans,sum);
        }
        return ans;
    }
};