class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len=nums.size();
        int idx=-1;
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1)return true;
        int mx=nums[idx];
        int mn=nums[idx+1];
        nums[idx]=mn;
        int ck=0;
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                ck=1;
                break;
            }
        }
        if(!ck)return true;
        ck=0;
        nums[idx]=mx;
        nums[idx+1]=mx;
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                ck=1;
                break;
            }
        }
        if(!ck)return true;
        else return false;
    }
};
