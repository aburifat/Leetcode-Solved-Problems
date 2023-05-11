class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mx_cost = (n*m) + 10;
        vector<vector<int>>cost(n,vector<int>(m,mx_cost));
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,0}});
        cost[0][0]=0;
        while(!pq.empty()){
            auto q=pq.top();
            pq.pop();
            int dis = -(q.first);
            int x = q.second.first;
            int y = q.second.second;
            int fm=grid[x][y]-1;
            int x_new=x+dx[fm];
            int y_new=y+dy[fm];
            if(x_new>=0&&y_new>=0&&x_new<n&&y_new<m){
                if(cost[x_new][y_new]>dis){
                    cost[x_new][y_new]=dis;
                    pq.push({-dis,{x_new,y_new}});
                }
            }
            for(int i=0;i<4;i++){
                if(i==fm)continue;
                x_new=x+dx[i];
                y_new=y+dy[i];
                if(x_new>=0&&y_new>=0&&x_new<n&&y_new<m){
                    if(cost[x_new][y_new]>dis+1){
                        cost[x_new][y_new]=dis+1;
                        pq.push({-dis-1,{x_new,y_new}});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};
