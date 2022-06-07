class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        ans.push_back(0);
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            int ans_size=ans.size();
            for(int i=ans_size-1;i>=0;i--){
                ans.push_back(ans[i]|mask);
            }
        }
        return ans;
    }
};