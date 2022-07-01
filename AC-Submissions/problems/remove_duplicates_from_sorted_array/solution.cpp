class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                nums[idx]=nums[i];
                idx++;
            }
        }
        return idx;
    }
};