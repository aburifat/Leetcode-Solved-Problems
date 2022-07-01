class Solution {
public:
    int distance(vector<int> a, vector<int> b){
        int x=abs(a[0]-b[0]);
        int y=abs(a[1]-b[1]);
        return max(x,y);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int len=points.size();
        int ans=0;
        for(int i=1;i<len;i++){
            ans+=distance(points[i-1],points[i]);
        }
        return ans;
    }
};
