public class Solution {
    private int[] nxt, siz;
    private bool[] visited;

    private int solve(int idx, int[] nums, int n){
        if(idx >= n) return 0;
        if(visited[idx]) return siz[idx];

        for(int i = idx+1; i<n ;i++){
            if(nums[i] % nums[idx] == 0){
                int val = solve(i, nums, n);
                if(val + 1 > siz[idx]){
                    siz[idx] = val + 1;
                    nxt[idx] = i;
                }
            }
        }

        visited[idx] = true;
        return siz[idx];
    }

    public IList<int> LargestDivisibleSubset(int[] nums) {
        int n = nums.Length;
        nxt = new int[n];
        siz = new int[n];
        visited = new bool[n];
        for(int i=0;i<n;i++){
            nxt[i] = i;
            siz[i] = 1;
            visited[i] = false;
        }

        int mxSiz = 0;
        int mxIdx = -1;

        Array.Sort(nums);

        for(int i=0; i<n ;i++){
            int tmp = solve(i, nums, n);
            if(tmp > mxSiz){
                mxSiz = tmp;
                mxIdx = i;
            }
        }

        List<int> ans = new List<int>();

        while(true){
            ans.Add(nums[mxIdx]);
            if(nxt[mxIdx] == mxIdx)break;
            mxIdx = nxt[mxIdx];
        }

        return ans;
    }
}
