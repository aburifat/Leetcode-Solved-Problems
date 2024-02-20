public class Solution {
    public int MissingNumber(int[] nums) {
        int ans = 0;
        for(int i = 1; i <= nums.Length; i++){
            ans ^= (i ^ nums[i-1]);
        }
        return ans;
    }
}