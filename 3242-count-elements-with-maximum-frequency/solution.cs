public class Solution {
    public int MaxFrequencyElements(int[] nums) {
        Array.Sort(nums);
        int ans = 0;
        int mxCount = 0;
        int count = 1;
        for(int i=1;i<nums.Length;i++){
            if(nums[i] != nums[i-1]){
                if(mxCount < count){
                    ans = mxCount = count;
                }
                else if(mxCount == count){
                    ans += count;
                }
                count = 1;
            }
            else{
                count++;
            }
        }
        if(mxCount < count){
            ans = count;
        }
        else if(mxCount == count){
            ans += count;
        }

        return ans;
    }
}
