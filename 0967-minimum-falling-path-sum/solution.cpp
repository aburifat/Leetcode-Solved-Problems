class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int tmp = matrix[i+1][j];
                if(j-1>=0){
                    tmp=min(tmp,matrix[i+1][j-1]);
                }
                if(j+1<n){
                    tmp=min(tmp,matrix[i+1][j+1]);
                }
                matrix[i][j]+=tmp;
            }
        }
        int ans = matrix[0][0];
        for(int i=1;i<n;i++){
            ans = min(ans,matrix[0][i]);
        }
        return ans;
    }
};
