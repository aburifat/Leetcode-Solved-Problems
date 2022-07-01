class Solution {
public:
    static bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        if(a.first==b.first){
            return a.second.first<b.second.first;
        }
        return a.first<b.first;
    }
    int distance(int aX,int aY, int bX, int bY){
        int x=abs(aX-bX);
        int y=abs(aY-bY);
        int dis=x+y;
        return dis;
    }
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    vector<pair<int,pair<int,int>>>pq;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dis=distance(i,j,rCenter,cCenter);
                //cout<<dis<<" "<<i<<" "<<j<<endl;
                pq.push_back({dis,{i,j}});
            }
        }
        sort(pq.begin(),pq.end(),cmp);
        vector<int>pr;
        pr.push_back(0);
        pr.push_back(0);
        vector<vector<int>>ans;
        for(int i=0;i<pq.size();i++){
            pair<int,pair<int,int>>tmp=pq[i];
            pr[0]=tmp.second.first;
            pr[1]=tmp.second.second;
            ans.push_back(pr);
        }
        return ans;
    }
};