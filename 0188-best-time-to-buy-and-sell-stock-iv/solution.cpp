int dp[1010][110][4];

void init(){
    for(int i=0;i<1010;i++){
        for(int j=0;j<110;j++){
            for(int k=0;k<4;k++)dp[i][j][k]=-1;
        }
    }
}

int ctDp(int idx, int ct, bool taken,int k, vector<int>& prices){
    if(ct>=k)return 0;
    if(idx>=prices.size())return 0;
    if(dp[idx][ct][taken]!=-1)return dp[idx][ct][taken];
    if(taken){
        dp[idx][ct][taken]=max(prices[idx]+ctDp(idx+1,ct+1,false,k,prices),ctDp(idx+1,ct,taken,k,prices));
    }else{
        dp[idx][ct][taken]=max(ctDp(idx+1,ct,true,k,prices)-prices[idx],ctDp(idx+1,ct,taken,k,prices));
    }
    return dp[idx][ct][taken];
}

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        init();
        int ans=ctDp(0,0,false,k,prices);
        return ans;
    }
};
