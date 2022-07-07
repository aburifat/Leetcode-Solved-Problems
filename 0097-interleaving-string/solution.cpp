class Solution {
    int dp[110][110][220];
    string a,b,c;
    int a_sz,b_sz,c_sz;
public:
    bool ckDp(int i, int j, int k){
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(i>=a_sz&&j>=b_sz){
            if(k>=c_sz)return 1;
            else return 0;
        }
        if(k==(c_sz-1)){
            int ck=0;
            if(i<a_sz){
                if(c[k]==a[i])ck=1;
            }
            if(j<b_sz){
                if(c[k]==b[j])ck=1;
            }
            return ck;
        }
        int val1=0,val2=0;
        if(j<b_sz&&b[j]==c[k]){
            val1=ckDp(i,j+1,k+1);
        }
        if(i<a_sz&&a[i]==c[k]){
            val2=ckDp(i+1,j,k+1);
        }
        return dp[i][j][k]=max(val1,val2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        a=s1,b=s2,c=s3;
        a_sz=a.size(),b_sz=b.size(),c_sz=c.size();
        if(a_sz+b_sz!=c_sz)return false;
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++){
                for(int k=0;k<220;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return ckDp(0,0,0);
    }
};
