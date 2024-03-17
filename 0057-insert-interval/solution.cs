public class Solution {
    public int[][] Insert(int[][] nums, int[] k) {
        List<int[]> ans = new();
        bool ck = false;
        for(int i = 0; i < nums.Length; i++){
            if(nums[i][0] < k[0] && nums[i][1] < k[0]){
                ans.Add(nums[i]);
            }
            else if(nums[i][0] > k[1] && nums[i][1] > k[1]){
                if(!ck){
                    ans.Add(k);
                    ck = true;
                }
                ans.Add(nums[i]);
            }
            else{
                k[0] = Math.Min(k[0], nums[i][0]);
                k[1] = Math.Max(k[1], nums[i][1]);
            }
        }
        if(!ck) ans.Add(k);
        return ans.ToArray();
    }
}
