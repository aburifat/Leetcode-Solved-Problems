#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<ll,ll>,bool>visited;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> adj=image;
        visited.clear();
        int n=image.size();
        int m=0;
        if(n!=0)m=adj[0].size();
        queue<pair<int,int> >q;
        int oldColor=adj[sr][sc];
        q.push({sr,sc});
        visited[{sr,sc}]=true;
        while(!q.empty()){
            sr=q.front().first;
            sc=q.front().second;
            q.pop();
            adj[sr][sc]=newColor;
            for(int i=0;i<4;i++){
                int u=sr+dx[i];
                int v=sc+dy[i];
                if(u>=0&&u<n&&v>=0&&v<m){
                    if(!visited[{u,v}]&&image[u][v]==oldColor){
                        q.push({u,v});
                        visited[{u,v}]=true;
                    }
                }
            }
        }
        return adj;
    }
};