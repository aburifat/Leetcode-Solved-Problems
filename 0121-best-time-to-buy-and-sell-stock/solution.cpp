class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>sell=prices;
        int len=sell.size();
        for(int i=len-2;i>=0;i--){
            sell[i]=max(sell[i],sell[i+1]);
        }
        int prof=0;
        for(int i=0;i<len;i++){
            prof=max(prof,(sell[i]-prices[i]));
        }
        return prof;
    }
};
