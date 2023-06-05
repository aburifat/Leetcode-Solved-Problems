class Solution {
public:
    void reduce(int& up, int& down){
        int gcd = __gcd(up,down);
        up/=gcd;
        down/=gcd;
    }
    bool checkStraightLine(vector<vector<int>>& c) {
        sort(c.begin(),c.end());
        int up = c[0][0]-c[1][0];
        int down = c[0][1]-c[1][1];
        reduce(up,down);
        bool ans=true;
        for(int i=2;i<(int)c.size();i++){
            int tmp_up=c[0][0]-c[i][0];
            int tmp_down = c[0][1]-c[i][1];
            reduce(tmp_up,tmp_down);
            if(tmp_up!=up||tmp_down!=down){
                ans=false;
                break;
            }
        }
        return ans;
    }
};
