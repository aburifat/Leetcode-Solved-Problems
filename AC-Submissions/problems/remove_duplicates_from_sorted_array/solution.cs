public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int len = nums.Length;
        int idx = 1;
        int pre = nums[0];
        for(int i=1;i<len;i++){
            if(nums[i]!=pre){
                pre=nums[i];
                nums[idx]=nums[i];
                idx += 1;
            }
        }
        return idx;
    }
}