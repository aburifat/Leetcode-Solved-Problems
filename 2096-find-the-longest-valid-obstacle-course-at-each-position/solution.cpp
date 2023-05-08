class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int len=obstacles.size();
        vector<int>sorted(len,1e9),ans;
        int right=0;
        for(int i=0;i<len;i++){
            int val=obstacles[i];
            int l=0,r=right;
            int idx=right;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(sorted[mid]<=val){
                    l=mid+1;
                }else{
                    idx=mid;
                    r=mid-1;
                }
            }
            ans.push_back(idx+1);
            sorted[idx]=val;
            if(idx==right)right++;
        }
        return ans;
    }
};
