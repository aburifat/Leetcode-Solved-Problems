class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            map<int,int>mp;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]){
                        //cout<<"1\n";
                        return false;
                    }else mp[board[i][j]]++;
                }
            }
            mp.clear();
        }
        for(int j=0;j<9;j++){
            map<int,int>mp;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    if(mp[board[i][j]]){
                        //cout<<"2\n";
                        return false;
                    }else mp[board[i][j]]++;
                }
            }
            mp.clear();
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<int,int>mp;
                for(int k=i;k<(i+3)&&k<9;k++){
                    for(int l=j;l<(j+3)&&l<9;l++){
                        if(board[k][l]!='.'){
                            if(mp[board[k][l]]){
                                //cout<<board[k][l]<<" 3\n";
                                return false;
                            }else mp[board[k][l]]++;
                        }
                    }
                }
                mp.clear();
            }
        }
        return true;
    }
};
