class Solution {
    int taken[10];
    vector<string>board;
    vector<vector<string>> ans;

    bool valid(int col, int row){
        for(int i=0;i<col;i++){
            if(taken[i]==row||abs(taken[i]-row)==abs(i-col))return false;
        }
        return true;
    }
    void nQueen(int idx, int n){
        for(int i=0;i<n;i++){
            if(valid(idx,i)){
                taken[idx]=i;
                board[idx][i]='Q';
                if(idx==n-1)ans.push_back(board);
                else nQueen(idx+1,n);
                board[idx][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<10;i++)taken[i]=-1;
        ans.clear();
        board.clear();
        string row = "";
        for(int i=0;i<n;i++)row+='.';
        for(int i=0;i<n;i++)board.push_back(row);
        nQueen(0,n);
        return ans;
    }
};