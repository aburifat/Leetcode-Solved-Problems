class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>ans;
        int ct=-1;
        for(int i=0;i<intervals.size();i++){
            if(ct==-1){
                ans.push_back(intervals[i]);
                ct++;
            }else{
                if(ans[ct][1]>=intervals[i][0])ans[ct][1]=max(ans[ct][1],intervals[i][1]);
                else{
                    ans.push_back(intervals[i]);
                    ct++;
                }
            }
        }
        return ans;
    }
};
