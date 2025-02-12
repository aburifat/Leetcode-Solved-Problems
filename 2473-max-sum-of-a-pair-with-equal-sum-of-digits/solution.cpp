class Solution {
    int getDigitSum(int num) {
        int sum = 0;
        while(num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> tmp;
        for(int i = 0; i < nums.size(); i++) {
            tmp.push_back({getDigitSum(nums[i]), nums[i]});
        }
        sort(tmp.begin(), tmp.end(), comp);
        int ans = -1;
        for(int i = 1; i < tmp.size(); i++) { 
            if (tmp[i-1].first == tmp[i].first) {
                ans = max(ans, tmp[i-1].second + tmp[i].second);
            }
        }
        return ans;
    }
};
