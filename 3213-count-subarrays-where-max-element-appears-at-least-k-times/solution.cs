public class Solution {
    public long CountSubarrays(int[] nums, int k) {
        int mx = 0;
        long ans = 0;
        for(int i = 0; i < nums.Length; i++) {
            mx = Math.Max(mx, nums[i]);
        }
        int l = 0, ct = 0;
        for(int r = 0; r < nums.Length; r++) {
            if(nums[r] == mx) ct++;
            while(l <= r && ct >= k) {
                if(nums[l] == mx) {
                    if(ct > k) ct--;
                    else break;
                }
                l++;
            }
            if(ct == k) {
                ans += (l+1);
            }
        }
        
        return ans;
    }
}
