class Solution {
public:
    vector<int> nxt;
    vector<int>siz;
    vector<bool>visited;
    int solve(int idx, vector<int>& nums, int n){
        if(idx>=n) return 0;
        if(visited[idx])return siz[idx];
        for(int i = idx+1; i<n; i++){
            if(nums[i]%nums[idx]==0){
                int val = solve(i, nums, n);
                if(val+1 > siz[idx]){
                    siz[idx] = val + 1;
                    nxt[idx] = i;
                }
            }
        }
        visited[idx] = true;
        return siz[idx];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nxt.resize(n);
        siz.assign(n,1);
        visited.assign(n,false);
        for(int i=0;i<n;i++){
            nxt[i] = i;
        }
        int mxAns = 0;
        int mxIdx = -1;
        for(int i=0;i<n;i++){
            int tmp = solve(i,nums,n);
            if(tmp > mxAns){
                mxAns = tmp;
                mxIdx = i;
            }
        }

        vector<int> ans;
        while(1){
            ans.push_back(nums[mxIdx]);
            if(nxt[mxIdx] == mxIdx)break;
            mxIdx = nxt[mxIdx];
        }
        return ans;
    }
};
