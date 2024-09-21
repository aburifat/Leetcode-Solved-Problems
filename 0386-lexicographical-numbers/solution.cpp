class Solution {
    vector<int> ans;
    void getNumber(int curr, int n) {
        if(curr > n) return;
        ans.push_back(curr);
        curr *= 10;
        for(int i = 0; i <= 9 ; i++){
            getNumber(curr + i, n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9 ; i++) {
            getNumber(i, n);
        }

        return ans;
    }
};
