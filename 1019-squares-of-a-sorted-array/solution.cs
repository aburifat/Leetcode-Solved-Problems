public class Solution {
    public int[] SortedSquares(int[] nums) {
        int[] ans = new int[nums.Length];
        int idx = nums.Length - 1;
        int l = 0, r = nums.Length - 1;
        while(l<=r){
            if(Math.Abs(nums[l]) > Math.Abs(nums[r])){
                ans[idx] = nums[l] * nums[l];
                l++;
            }else{
                ans[idx] = nums[r] * nums[r];
                r--;
            }
            idx--;
        }
        return ans;
    }
}
