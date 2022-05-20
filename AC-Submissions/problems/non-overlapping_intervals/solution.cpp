class Solution {
    vector<int>right;
    unordered_map<int,int>left,mp;
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        left.clear();
        right.clear();
        mp.clear();
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            if(!mp[r]){
                right.push_back(r);
                mp[r]++;
                left[r]=l;
            }
            else left[r]=max(left[r],l);
        }
        sort(right.begin(),right.end());
        int ans=n;
        int nowLeft=-1e6;
        for(int i=0;i<(int)right.size();i++){
            if(left[right[i]]>=nowLeft){
                nowLeft=right[i];
                ans--;
            }
        }
        return ans;
    }
};