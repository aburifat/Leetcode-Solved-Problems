class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        int row=1,col=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(i==0&&j==0)row=0,col=0;
                    else if(i==0&&j!=0)row=0,matrix[0][j]=0;
                    else if(j==0&&i!=0)col=0,matrix[i][0]=0;
                    else{
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<m;j++)matrix[i][j]=0;
            }
        }
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<n;i++)matrix[i][j]=0;
            }
        }
        if(col==0)for(int i=0;i<n;i++)matrix[i][0]=0;
        if(row==0)for(int j=0;j<m;j++)matrix[0][j]=0;
    }
};