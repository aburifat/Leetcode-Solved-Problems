class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows,vector<int>());
        int arr[numRows+5][numRows+5];
        for(int i=0;i<=numRows;i++){
            arr[0][i]=arr[i][0]=1;
        }
        for(int i=1;i<numRows;i++){
            for(int j=1;j<(numRows-i);j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                ans[i].push_back(arr[i-j][j]);
            }
        }
        return ans;
    }
};
