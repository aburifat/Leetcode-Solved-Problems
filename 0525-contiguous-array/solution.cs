public class Solution {
    public int FindMaxLength(int[] nums) {
        Dictionary<int, int> dic = new();
        dic.Add(0, -1);
        int ans = 0, sum = 0;
        for(int i = 0; i < nums.Length; i++){
            if(nums[i] == 0) sum--;
            else sum++;
            if(dic.ContainsKey(sum)){
                ans = Math.Max(ans, i - dic[sum]);
            }
            else{
                dic.Add(sum, i);
            }
        }
        return ans;
    }
}
