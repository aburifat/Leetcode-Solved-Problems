class NumMatrix {
    long long sum[210][210];
    int n=0, m=0;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        if(n>0)m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum[i][j]=(long long)matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i][j]+=sum[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                sum[i][j]+=sum[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if((row1+col1)>(row2+col2)){
            swap(row1,row2);
            swap(col1,col2);
        }
        int ans=0;
        if(row2>=0&&row2<n&&col2>=0&&col2<m){
            ans=sum[row2][col2];
            if(row1>0&&row1<n&&col1>0&&col1<m){
                ans+=sum[row1-1][col1-1];
                ans-=sum[row1-1][col2];
                ans-=sum[row2][col1-1];
            }else if(row1>0&&row1<n){
                ans-=sum[row1-1][col2];
            }else if(col1>0&&col1<m){
                ans-=sum[row2][col1-1];
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
