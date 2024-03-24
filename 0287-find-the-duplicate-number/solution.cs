public class Solution {
    public int FindDuplicate(int[] nums) {
        bool[] ck = new bool[nums.Length];
        int ans = 1;
        for(int i = 0; i < nums.Length; i++){
            if(ck[nums[i]]){
                ans = nums[i];
                break;
            }
            ck[nums[i]] = true;
        }
        return ans;
    }
}
