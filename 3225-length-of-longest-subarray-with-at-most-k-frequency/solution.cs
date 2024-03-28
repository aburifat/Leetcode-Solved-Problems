public class Solution {
    public int MaxSubarrayLength(int[] nums, int k) {
        Dictionary<int, int> ct = new();
        int left = 0, ans = 0;
        for(int right = 0; right < nums.Length; right++) {
            if(!ct.ContainsKey(nums[right])) ct.Add(nums[right], 1);
            else ct[nums[right]]++;
            while(left <= right && ct[nums[right]] > k) ct[nums[left++]]--;
            if(left <= right) ans = Math.Max(ans, right - left + 1);
        }

        return ans;
    }
}
