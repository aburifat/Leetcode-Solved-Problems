class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans = vector<int>(n, 0);
        int val = 1;
        for(int i = k - 1; i >= 0; i -= 2) {
            ans[i] = val++;
        }
        for(int i = (k % 2); i < k; i += 2) {
            ans[i] = val++;
        }

        for(int i = k; i < n; i++) {
            ans[i] = val++;
        }
        return ans;
    }
};
