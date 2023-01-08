class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len=points.size();
        int ans=0;
        for(int i=0;i<len;i++){
            int max_now=0;
            map<pair<int,int>,int>mp;
            for(int j=i+1;j<len;j++){
                int x=points[i][0]-points[j][0];
                int y=points[i][1]-points[j][1];
                int gcd=__gcd(x,y);
                x/=gcd;
                y/=gcd;
                mp[{x,y}]++;
                max_now=max(max_now,mp[{x,y}]);
            }
            ans=max(ans,max_now);
        }
        return ans+1;
    }
};
