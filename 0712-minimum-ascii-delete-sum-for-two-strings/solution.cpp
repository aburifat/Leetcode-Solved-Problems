class Solution {
    int dp[1010][1010];
    int vals[1010][1010];
public:
    void init(){
        for(int i=0;i<1010;i++){
            dp[i][0]=0;
            for(int j=0;j<1010;j++)vals[i][j]=0;
        }
        for(int j=0;j<1010;j++){
            dp[0][j]=0;
        }
    }
    int buildLCS(string& w1, string& w2){
        int mxLCS=0;
        int dltCost=0;
        for(int i=0;i<w1.size();i++){
            for(int j=0;j<w2.size();j++){
                if(w1[i]==w2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    vals[i+1][j+1]=(int)w1[i]+vals[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                    vals[i+1][j+1]=max(vals[i][j+1],vals[i+1][j]);
                }
                mxLCS=max(mxLCS,dp[i+1][j+1]);
                dltCost=max(dltCost,vals[i+1][j+1]);
                //cout<<dp[i+1][j+1]<<" ";
            }
            //cout<<endl;
        }
        return dltCost;
    }
    int minimumDeleteSum(string s1, string s2) {
        init();
        int ans=buildLCS(s1,s2);
        int sum=0;
        for(int i=0;i<s1.size();i++)sum=sum+(int)s1[i];
        for(int i=0;i<s2.size();i++)sum=sum+(int)s2[i];
        ans=sum-(2*ans);
        return ans;
    }
};
