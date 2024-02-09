public class Solution {
    Dictionary<Tuple<int,int>,int> dp = new Dictionary<Tuple<int,int>,int>();
    int Solve(int target, int[] nums, int idx, int n){
        if(idx == n){
            if(target == 0) return 1;
            else return 0;
        }
        Tuple<int,int> key = new Tuple<int,int>(target,idx);
        if(dp.ContainsKey(key) == true) return dp[key];
        return dp[key] = Solve(target + nums[idx], nums, idx+1, n) + Solve(target - nums[idx], nums, idx+1, n);
    }
    public int FindTargetSumWays(int[] nums, int target) {
        return Solve(target,nums,0,nums.Length);
    }
}
