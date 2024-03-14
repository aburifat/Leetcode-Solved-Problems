public class Solution {
    public int NumSubarraysWithSum(int[] nums, int goal) {
        int[] preSum = new int[nums.Length + 1];
        preSum[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.Length; i++){
            sum += nums[i];
            if(sum >= goal){
                int diff = sum - goal;
                ans += preSum[diff];
            }
            preSum[sum]++;
        }
        return ans;
    }
}
