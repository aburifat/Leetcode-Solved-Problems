class Solution {
public:
    int dp[30010][2];
    int ctDp(int nowIdx, bool bought, int buyPrice,int mxIdx,vector<int>& prices){
        if(dp[nowIdx][bought]!=-1)return dp[nowIdx][bought];
        if(nowIdx==mxIdx){
            if(bought)dp[nowIdx][bought]=max(0,prices[nowIdx]-buyPrice);
            else dp[nowIdx][bought]=0;
        }else{
            if(bought){
                int sellPrice=prices[nowIdx]-buyPrice;
                int val2=max(0,sellPrice+ctDp(nowIdx+1,true,prices[nowIdx],mxIdx,prices));
                int val1=max(0,ctDp(nowIdx+1,true,buyPrice,mxIdx,prices));
                dp[nowIdx][bought]=max(val1,val2);
            }else{
                int val1=max(0,ctDp(nowIdx+1,false,0,mxIdx,prices));
                int val2=max(0,ctDp(nowIdx+1,true,prices[nowIdx],mxIdx,prices));
                dp[nowIdx][bought]=max(val1,val2);
            }
        }
        return dp[nowIdx][bought];
    }
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        for(int i=0;i<30010;i++){
            for(int j=0;j<2;j++)dp[i][j]=-1;
        }
        int ans=ctDp(0,false,0,len-1,prices);
        return ans;
    }
};
