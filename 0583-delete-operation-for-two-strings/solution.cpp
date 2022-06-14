class Solution {
    int dp[510][510];
public:
    void init(){
        for(int i=0;i<510;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<510;j++){
            dp[0][j]=0;
        }
    }
    int buildLCS(string& w1, string& w2){
        int mxLCS=0;
        for(int i=0;i<w1.size();i++){
            for(int j=0;j<w2.size();j++){
                if(w1[i]==w2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
                mxLCS=max(mxLCS,dp[i+1][j+1]);
                //cout<<dp[i+1][j+1]<<" ";
            }
            //cout<<endl;
        }
        return mxLCS;
    }
    int minDistance(string word1, string word2) {
        init();
        int len=word1.size()+word2.size();
        int val=buildLCS(word1,word2);
        return len-(2*val);
    }
};
