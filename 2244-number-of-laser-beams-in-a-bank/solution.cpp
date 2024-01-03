class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = bank.size();
        int col = bank[0].size();
        int pre = 0;
        int ans = 0;
        for(int i = 0; i < row; i++){
            int curr = 0;
            for(int j=0; j<col;j++){
                if(bank[i][j]=='1')curr++;
            }
            ans += (pre*curr);
            if(curr>0)pre = curr;
        }
        return ans;
    }
};
