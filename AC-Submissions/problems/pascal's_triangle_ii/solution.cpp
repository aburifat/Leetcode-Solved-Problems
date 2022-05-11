class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows=rowIndex+1;
        vector<int>ans;
        int arr[numRows+5][numRows+5];
        for(int i=0;i<=numRows;i++){
            arr[0][i]=arr[i][0]=1;
        }
        for(int i=1;i<numRows;i++){
            for(int j=1;j<(numRows-i);j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        for(int j=0;j<=rowIndex;j++){
            ans.push_back(arr[rowIndex-j][j]);
        }
        return ans;
    }
};