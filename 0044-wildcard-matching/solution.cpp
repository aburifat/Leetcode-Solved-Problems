class Solution {
public:
    bool isMatch(string s, string p) {
        int lens=s.size();
        int lenp=p.size();
        vector<bool>a(lens+5,false);
        vector<bool>b(lens+5,false);
        a[0]=true;
        bool onlyStarTillNow=true;
        for(int i=1;i<=lenp;i++){
            if(p[i-1]!='*')onlyStarTillNow=false;
            if(onlyStarTillNow)b[0]=true;
            else b[0]=false;
            for(int j=1;j<=lens;j++){
                if(p[i-1]=='*')b[j]=a[j-1]|a[j]|b[j-1];
                else if(p[i-1]=='?')b[j]=a[j-1];
                else if(p[i-1]==s[j-1])b[j]=a[j-1];
                else b[j]=false;
            }
            a=b;
        }
        return a[lens];
    }
};
