class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int len =colors.size();
        int cost=0;
        for(int i=1;i<len;i++){
            if(colors[i-1]==colors[i]){
                cost+=min(neededTime[i-1],neededTime[i]);
                neededTime[i]=max(neededTime[i-1],neededTime[i]);
            }
        }
        return cost;
    }
};