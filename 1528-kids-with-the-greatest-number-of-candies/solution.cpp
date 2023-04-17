class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=0;
        for(int i=0;i<(int)candies.size();i++){
            mx=max(mx,candies[i]);
        }
        vector<bool>ans;
        for(int i=0;i<(int)candies.size();i++){
            if(candies[i]+extraCandies>=mx)ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
