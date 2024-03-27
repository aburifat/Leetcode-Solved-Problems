public class Solution {
    public int NumSubarrayProductLessThanK(int[] nums, int k) {
        int pre = 0, mul = 1, ans = 0;
        for(int i = 0; i < nums.Length; i++) {
            mul *= nums[i];
            while(pre <= i && mul >= k) {
                mul /= nums[pre++];
            }
            if(pre <= i) ans += (i - pre + 1);
        }
        
        return ans;
    }
}
