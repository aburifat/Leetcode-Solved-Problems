class Solution {
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int n,m,len;
    vector<vector<char>>board;
    bool visited[10][10];
    string word;
public:
    bool findWord(int x, int y ,int idx){
        bool ck=false;
        if(idx==len)return true;
        if((x>=n)||(y>=m)||(x<0)||(y<0)||(word[idx]!=board[x][y])||visited[x][y]==true)return false;
        for(int i=0;i<4;i++){
            visited[x][y]=true;
            ck=ck|findWord(x+dx[i],y+dy[i],idx+1);
            visited[x][y]=false;
        }
        return ck;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        this->word=word;
        memset(visited, false, sizeof(visited));
        n=board.size();
        m=board[0].size();
        len=word.size();
        char st=word[0];
        vector<pair<int,int>>stpos;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==st)stpos.push_back({i,j});
            }
        }
        bool ck=false;
        int test=stpos.size();
        for(int i=0;i<test;i++){
            int x=stpos[i].first;
            int y=stpos[i].second;
            ck=findWord(x,y,0);
            if(ck==true)break;
        }
        return ck;
    }
};
