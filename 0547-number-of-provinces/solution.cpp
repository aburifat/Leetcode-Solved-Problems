class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int ct = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ct++;
                queue<int>q;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int s = q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[s][j]&&!visited[j]){
                            visited[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ct;
    }
};
