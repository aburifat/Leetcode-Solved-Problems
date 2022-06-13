class Solution {
    int dp[100000][2];
    vector<int>arr;
public:
    void init(){
        for(int i=0;i<100000;i++){
            for(int j=0;j<2;j++)dp[i][j]=-1;
        }
    }
    int ctDp(int buyPrice,int bought,int nowIdx,int mxIdx){
        if(dp[nowIdx][bought]!=-1)return dp[nowIdx][bought];
        if(nowIdx==mxIdx){
            if(bought) return dp[nowIdx][bought]=max(0,arr[nowIdx]-buyPrice);
            else return dp[nowIdx][bought]=0;
        }
        if(bought){
            int sell_price=max(0,arr[nowIdx]-buyPrice);
            int val1=sell_price+ctDp(arr[nowIdx],true,nowIdx+1,mxIdx);
            int val2=ctDp(buyPrice,bought,nowIdx+1,mxIdx);
            dp[nowIdx][bought]=max(val1,val2);
        }else{
            int val1=ctDp(0,false,nowIdx+1,mxIdx);
            int val2=ctDp(arr[nowIdx],true,nowIdx+1,mxIdx);
            dp[nowIdx][bought]=max(val1,val2);
        }
        return dp[nowIdx][bought];
    }
    int maxProfit(vector<int>& prices) {
        init();
        arr=prices;
        int len=prices.size();
        int ans=ctDp(0,false,0,len-1);
        return ans;
    }
};