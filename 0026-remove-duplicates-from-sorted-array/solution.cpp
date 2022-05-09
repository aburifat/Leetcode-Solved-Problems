class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int val;
        if(nums.size()>0){
            val=nums[0];
            k=1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=val){
                val=nums[i];
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};
