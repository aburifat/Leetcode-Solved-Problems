public class Solution {
    public int[] RearrangeArray(int[] nums) {
        int n = nums.Length;
        int[] ans = new int[n];
        int odd = 1, even  = 0;
        for(int i=0;i<nums.Length;i++){
            if(nums[i] < 0){
                ans[odd] = nums[i];
                odd+=2;
            }
            else{
                ans[even] = nums[i];
                even+=2;
            }
        }
        return ans;
    }
}