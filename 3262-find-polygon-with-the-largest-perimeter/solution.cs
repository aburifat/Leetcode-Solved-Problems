public class Solution {
    public long LargestPerimeter(int[] nums) {
        int n = nums.Length;
        long[] sum = new long[n];
        Array.Sort(nums);
        sum[0] = nums[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1] + nums[i];
        }

        long ans = -1;
        for(int i = n-1; i>=1; i--){
            long val = sum[i] - sum[i-1];
            if(val < sum[i-1]){
                ans = sum[i];
                break;
            }
        }

        return ans;
    }
}
