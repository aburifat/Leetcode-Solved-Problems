public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int len = nums.Length;
        for(int i = 0; i < len; i++){
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
                (nums[i], nums[nums[i] - 1]) = (nums[nums[i] - 1], nums[i]);
            }
        }
        int ans = len + 1;
        for(int i = 0; i < len ; i++){
            if(nums[i] != i + 1){
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
}
