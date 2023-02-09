public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int len = nums.Length;
        int idx = 0;
        for(int i=0;i<len;i++){
            if(nums[i]!=val){
                nums[idx]=nums[i];
                idx+=1;
            }
        }
        return idx;
    }
}