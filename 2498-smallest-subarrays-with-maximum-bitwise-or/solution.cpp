class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int len = nums.size();
        int arr[len + 1][32];
        int suff[len + 1];
        for(int j = 0; j < 32; j++) {
            arr[0][j] = 0;
        }
        for(int i = 1; i <= len; i++) {
            for(int j = 0; j < 32; j++) {
                arr[i][j] = arr[i - 1][j] + ((nums[i - 1] & (1LL << j)) ? 1 : 0);
            }
        }
        suff[len] = nums[len - 1];
        for(int i = len - 1; i >= 1; i--) {
            suff[i] = nums[i - 1] | suff[i + 1];
        }
        vector<int> ans;
        for(int i = 1; i <= len; i++) {
            int l = i;
            int r = len;
            int idx = len;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                int val = 0;
                for(int j = 0; j < 32; j++) {
                    if(arr[mid][j] - arr[i - 1][j]) val |= (1LL << j);
                }
                if(val == suff[i]) {
                    idx = mid;
                    r = mid - 1;
                }
                else if(val > suff[i]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            ans.push_back(idx - i + 1);
        }
        return ans;
    }
};
