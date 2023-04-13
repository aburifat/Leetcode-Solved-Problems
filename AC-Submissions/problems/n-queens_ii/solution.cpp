class Solution {
    int taken[10];
    int ct = 0;
    bool valid(int col, int row){
        for(int i=0;i<col;i++){
            if(taken[i]==row||abs(i-col)==abs(taken[i]-row))return false;
        }
        return true;
    }
    void nQueen(int idx, int n){
        for(int i=0;i<n;i++){
            if(valid(idx,i)){
                taken[idx]=i;
                if(idx==n-1)ct++;
                else nQueen(idx+1,n);
            }
        }
    }
public:
    int totalNQueens(int n) {
        for(int i=0;i<n;i++)taken[i]=-1;
        ct=0;
        nQueen(0,n);
        return ct;
    }
};