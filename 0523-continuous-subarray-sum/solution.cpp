class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len=nums.size();
        map<int,int>mp;
        int sum=0;
        bool ck=false;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            sum%=k;
            if(sum==0&&i!=0){
                ck=true;
                break;
            }
            else if(!mp[sum])mp[sum]=i+1;
            else if(abs(mp[sum]-(i+1))>=2){
                ck=true;
                break;
            }
        }
        return ck;
    }
};
