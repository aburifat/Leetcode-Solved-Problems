class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>demo;
        for(int i=0;i<numRows;i++){
            ans.push_back(demo);
            for(int j=0;j<=i;j++){
                if(j==0||j==i)ans[i].push_back(1);
                else ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
        }
        return ans;
    }
};