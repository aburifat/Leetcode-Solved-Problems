public class Solution {
    public int MajorityElement(int[] nums) {
        int ct = 0;
        int ans = -1;
        for(int i = 0; i < nums.Length; i++){
            if(nums[i] == ans) ct++;
            else{
                if(ct > 0) ct--;
                else{
                    ct++;
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
}
