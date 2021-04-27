class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        if(row==0)return 0;
        int col=matrix[0].size();
        int arr[row+5][col+5];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j]=matrix[i][j]-'0';
                if(i!=0)arr[i][j]+=arr[i-1][j];
            }
        }
        int tmp=0,ans=0;
        for(int i=1;i<=row;i++){
            for(int j=i-1;j<row; j++){
                int now=0;
                for(int k=0;k<col;k++){
                    tmp+=arr[j][k];
                    if((j-i)>=0)tmp-=arr[j-i][k];
                    int lrow=i;
                    int lcol=k-now+1;
                    if(tmp==(lrow*lcol)){
                        if(lrow==lcol)ans=max(ans,tmp);
                    }
                    else{
                        tmp=0;
                        now=k+1;
                    }
                }
                tmp=0;
            }
            tmp=0;
        }
    return ans;
    }
};
