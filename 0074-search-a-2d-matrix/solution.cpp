class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;
        bool ck =false;
        while(top<=bottom && left<=right){
            int x = top + (bottom-top)/2;
            int y = left + (right-left)/2;
            if(matrix[x][y]==target){
                ck=true;
                break;
            }
            else if(matrix[x][y]<target){
                if(matrix[x][n-1]<target){
                    top=x+1;
                }else{
                    left=y+1;
                }
            }else{
                if(matrix[x][0]>target){
                    bottom = x-1;
                }else{
                    right=y-1;
                }
            }
        }
        return ck;
    }
};
