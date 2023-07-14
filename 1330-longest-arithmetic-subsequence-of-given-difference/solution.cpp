class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        int len = arr.size();
        unordered_map<int,int>dp;
        int ans = 1;
        for(int i=0;i<len;i++){
            int num = arr[i];
            if(dp.find(num-dif)!=dp.end()){
                dp[num]=dp[num-dif]+1;
            }else{
                dp[num] = 1;
            }
            ans = max(ans,dp[num]);
        }
        return ans;
    }
};
