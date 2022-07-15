class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct=0;
        for(int i=0,j=0;i<nums.size()&&j<nums.size();){
            if(nums[i]!=0&&nums[j]!=0)i++,j++;
            else if(nums[i]!=0)i++;
            else if(nums[j]==0)j++,ct++;
            else nums[i]=nums[j],nums[j]=0,i++,j++;
        }
        for(int i=nums.size()-1;ct;i--,ct--){
            nums[i]=0;
        }
    }
};
