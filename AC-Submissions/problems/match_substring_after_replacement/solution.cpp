class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int ch[300][300];
        for(int i=0;i<300;i++){
            for(int j=0;j<300;j++){
                ch[i][j]=-1;
            }
        }
        for(int i=0;i<mappings.size();i++){
            ch[mappings[i][0]-'0'][mappings[i][1]-'0']=1;
        }
        int len_s=s.size();
        int len_sub=sub.size();
        int ck=1;
        for(int i=0;i<len_s;i++){
            for(int j=0;j<len_sub;j++){
                if(i+j>=len_s)break;
                if(s[i+j]!=sub[j]){
                    if(ch[sub[j]-'0'][s[i+j]-'0']==-1)break;
                    if(j==len_sub-1){
                        ck=0;
                        break;
                    }
                }
                if(j==len_sub-1){
                    ck=0;
                    break;
                }
            }
            if(ck==0)break;
        }
        if(!ck)return true;
        return false;
    }
};