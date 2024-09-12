class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<int, int> count;
        for(int idx = 0; idx < words.size(); idx++) {
            int mask = 0;
            for(int i = 0; i < words[idx].size(); i++) {
                mask |= (1 << (words[idx][i] - 'a'));
            }
            count[mask]++;
        }
        int ans = 0;
        for(auto it = count.begin(); it != count.end(); it++) {
            int n = it-> second;
            ans += (n * (n - 1) / 2);
        }

        return ans;
    }
};
