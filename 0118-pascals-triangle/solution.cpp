class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int row=0;row<numRows;row++){
            ans.push_back(vector<int>(1,1));
            if(row==0)continue;
            if(row>=2){
                for(int i=0;i<row-1;i++){
                    ans[row].push_back(ans[row-1][i]+ans[row-1][i+1]);
                }
            }
            ans[row].push_back(1);
        }
        return ans;
    }
};
