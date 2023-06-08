class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        int idx=0;
        for(int i=n-1;i>=0;i--){
            for(int j=idx;j<m;j++){
                if(grid[i][j]<0){
                    idx=j;
                    ans+=(m-j);
                    break;
                }
            }
        }
        return ans;
    }
};
