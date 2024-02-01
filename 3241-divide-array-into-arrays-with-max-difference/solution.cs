public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        int[][] ans = new int[nums.Length/3][];
        for(int i=0; i<nums.Length; i+=3){
            if(nums[i+2] - nums[i] <= k){
                ans[i/3] = new int[3]{nums[i], nums[i+1], nums[i+2]};
            }else return new int[0][];
        }
        return ans;
    }
}
