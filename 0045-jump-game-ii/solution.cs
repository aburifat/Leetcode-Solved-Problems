public class Solution {
    int[] mem;
    int dp(int idx, int[] nums){
        if(idx >= nums.Length - 1) return 0;
        if(mem[idx] != -1) return mem[idx];
        int mn = nums.Length + 1;
        for(int i = 1; i <= nums[idx]; i++){
            mn = Math.Min(mn, 1 + dp(idx + i, nums));
        }
        return mem[idx] = mn;
    }
    public int Jump(int[] nums) {
        mem = new int[nums.Length];
        for(int i=0; i < nums.Length; i++) mem[i] = -1;
        return dp(0, nums);
    }
}
