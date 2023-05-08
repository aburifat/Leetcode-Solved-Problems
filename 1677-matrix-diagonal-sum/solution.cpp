class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len=mat.size();
        int sum=0;
        int d1,d2;
        for(int i=0;i<len;i++){
            d1=i;
            d2=len-i-1;
            sum+=mat[i][d1];
            if(d1!=d2)sum+=mat[i][d2];
        }
        return sum;
    }
};
