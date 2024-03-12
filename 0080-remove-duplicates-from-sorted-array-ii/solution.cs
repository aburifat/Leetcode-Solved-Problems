public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int currNum = -1;
        int ct = 0;
        int k = 0;
        for(int i = 0, j = 0; j < nums.Length; j++){
            if(nums[j] != currNum){
                currNum = nums[j];
                ct = 1;
            }
            else ct++;
            nums[i] = nums[j];
            if(ct <= 2){
                i++;
                k++;
            }
        }
        return k;
    }
}
