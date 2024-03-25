public class Solution {
    public IList<int> FindDuplicates(int[] nums) {
        List<int> ans = new();
        for(int i = 0; i < nums.Length; i++) {
            int value = nums[i] >= 0 ? nums[i] : -nums[i];
            if(nums[value - 1] < 0) {
                ans.Add(value);
            }
            else {
                nums[value - 1] = -nums[value - 1];
            }
        }
        return ans;
    }
}
