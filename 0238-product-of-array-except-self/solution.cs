public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int[] ans = new int[nums.Length];
        for(int i = 0; i< nums.Length; i++) ans[i] = 1;
        for(int i = 1; i < nums.Length; i++){
            ans[i] = ans[i - 1] * nums[i -1];
        }
        int suf = 1;
        for(int i = nums.Length - 2; i >= 0; i--){
            ans[i] *= suf;
            ans[i] *= nums[i + 1];
            suf *= nums[i + 1];
        }
        return ans;
    }
}
