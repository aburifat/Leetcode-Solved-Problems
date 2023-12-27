class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int preTime = 0;
        char preColor = '#';
        int ans = 0;
        for(int i=0;i<(int)colors.size();i++){
            if(preColor == colors[i]){
                ans += min(preTime,neededTime[i]);
                preTime = max(preTime, neededTime[i]);
            }else{
                preTime = neededTime[i];
                preColor = colors[i];
            }
        }
        return ans;
    }
};
