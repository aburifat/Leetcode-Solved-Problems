public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] ans = new int[2];
        Dictionary<int,int> dic = new Dictionary<int,int>();
        int len = nums.Length;
        for(int i=0;i<len;i++){
            int rem = target - nums[i];
            if(dic.ContainsKey(rem)){
                ans[0]=dic[rem];
                ans[1]=i;
                return ans;
            }
            dic[nums[i]]=i;
        }
        return ans;
    }
}
