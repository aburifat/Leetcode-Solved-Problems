class Solution {
    int ckline[2][9];
    int cksec[3][3];
    void init(){
        for(int i=0;i<2;i++){
            for(int j=0;j<9;j++){
                ckline[i][j]=0;
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cksec[i][j]=0;
            }
        }
    }
    void toggle_bit(int& mask, int bit){
        mask ^= (1 << bit);
    }
    void toggle(int i, int j, int k){
        toggle_bit(ckline[0][i],k);
        toggle_bit(ckline[1][j],k);
        toggle_bit(cksec[i/3][j/3],k);
    }
    void fill(vector<vector<char>> board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int k = board[i][j]-'0';
                    toggle(i,j,k);
                }
            }
        }
    }
    tuple<int,int>get_next(int i, int j){
        j++;
        if(j>=9)i++;
        j%=9;
        return {i,j};
    }
    bool ck_bit(int mask, int bit){
        if(mask&(1<<bit))return true;
        return false;
    }
    bool ck_val(int i, int j, int k){
        bool ck=true;
        if(ck_bit(ckline[0][i],k)||ck_bit(ckline[1][j],k)||ck_bit(cksec[i/3][j/3],k))ck=false;
        return ck;
    }
    bool solve(int i, int j, vector<vector<char>>& board){
        if(i>8)return true;
        if(board[i][j]=='.'){
            for(int k=1;k<10;k++){
                if(ck_val(i,j,k)){
                    board[i][j]=k+'0';
                    toggle(i,j,k);
                    if(i==8&&j==8)return true;
                    auto[nxt_i,nxt_j] = get_next(i,j);
                    bool ck=solve(nxt_i, nxt_j, board);
                    if(ck==true)return true;
                    toggle(i,j,k);
                    board[i][j]='.';
                }

            }
        }else{
            if(i>8&&j>8)return true;
            auto[nxt_i,nxt_j] = get_next(i,j);
            bool ck=solve(nxt_i, nxt_j, board);
            if(ck==true)return true;
            else return false;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        init();
        fill(board);
        bool ck=solve(0,0,board);
    }
};
