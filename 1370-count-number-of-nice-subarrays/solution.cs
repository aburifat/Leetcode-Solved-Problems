public class Solution {
    public int NumberOfSubarrays(int[] nums, int k) {
        List<int> evenCnt = new List<int>();
        int cnt = 0;
        for(int i = 0; i < nums.Length; i++) {
            if(nums[i] % 2 != 0) {
                evenCnt.Add(cnt);
                cnt = 0;
            }
            else {
                cnt++;
            }
            if(i == nums.Length - 1) {
                evenCnt.Add(cnt);
            }
        }
        int ans = 0;
        if(evenCnt.Count - 1 < k) return ans;
        for(int startIdx = 0, endIdx = k - 1; endIdx < evenCnt.Count - 1; startIdx++, endIdx++) {
            int leftCnt = evenCnt[startIdx] + 1;
            int rightCnt = evenCnt[endIdx + 1] + 1;
            ans += (leftCnt * rightCnt);
        }
        return ans;
    }
}
