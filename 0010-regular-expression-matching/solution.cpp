class Solution {
    vector<char>pt;
    vector<int>type;
    int dp[25][30];
public:
    void init(){
        for(int i=0;i<25;i++){
            for(int j=0;j<30;j++)dp[i][j]=-1;
        }
        pt.clear();
        type.clear();
    }
    bool ckDp(string& s, int x, int y){
        if(x>=s.size()&&y>=pt.size())return 1;
        if(y>=pt.size())return 0;
        if(x>=s.size()){
            bool ck=true;
            for(int i=y;i<type.size();i++){
                if(type[i]!=0){
                    ck=false;
                    break;
                }
            }
            return ck;
        }
        if(dp[x][y]!=-1)return dp[x][y];
        if(type[y]==0){
            if(pt[y]=='.'||pt[y]==s[x])dp[x][y]=ckDp(s,x,y+1)|ckDp(s,x+1,y)|ckDp(s,x+1,y+1);
            else dp[x][y]=ckDp(s,x,y+1);
        }else{
            if(pt[y]=='.'||pt[y]==s[x])dp[x][y]=ckDp(s,x+1,y+1);
            else dp[x][y]=0;
        }
        return dp[x][y];
    }
    bool isMatch(string s, string p) {
        init();
        for(int i=0;i<p.size();i++){
            pt.push_back(p[i]);
            if(i<p.size()-1&&p[i+1]=='*'){
                type.push_back(0);
                i++;
            }else type.push_back(1);
        }
        bool ck=ckDp(s,0,0);
        return ck;
    }
};
