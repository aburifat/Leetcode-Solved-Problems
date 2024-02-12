public class Solution {
    public IList<int> MajorityElement(int[] nums) {
        int count1 = 0, count2 = 0;
        int candidate1 = int.MaxValue, candidate2 = int.MaxValue;
        for(int i=0;i<nums.Length;i++){
            if(candidate1 == nums[i]){
                count1++;
            }else if(candidate2 == nums[i]){
                count2++;
            }else if(count1 == 0){
                candidate1 = nums[i];
                count1++;
            }else if(count2 == 0){
                candidate2 = nums[i];
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0; count2 = 0;
        for(int i=0;i<nums.Length;i++){
            if(candidate1 == nums[i])count1++;
            else if(candidate2 == nums[i])count2++;
        }
        List<int> ans = new List<int>();
        if(count1 > (nums.Length / 3)){
            ans.Add(candidate1);
        }
        if(count2 > (nums.Length / 3)){
            ans.Add(candidate2);
        }
        return ans;
    }
}
