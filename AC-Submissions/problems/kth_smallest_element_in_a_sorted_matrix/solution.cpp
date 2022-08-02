class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<m;i++)pq.push({matrix[0][i],{0,i}});
        int ct=0;
        int val=matrix[0][0];
        while(!pq.empty()){
            ct++;
            val=pq.top().first;
            if(ct==k)break;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x+1<n){
                pq.push({matrix[x+1][y],{x+1,y}});
            }
        }
        return val;
    }
};