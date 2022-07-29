class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>bestFuture=prices;
        int myProfit=0;
        for(int i=bestFuture.size()-1;i>=0;i--){
            if(i!=bestFuture.size()-1)bestFuture[i]=max(bestFuture[i],bestFuture[i+1]);
            myProfit=max(myProfit,bestFuture[i]-prices[i]);
        }
        return myProfit;
    }
};
