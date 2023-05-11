class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        deque<int>dq;
        int len=status.size();
        vector<bool>visited(len,false);
        for(int i=0;i<(int)initialBoxes.size();i++){
            int b=initialBoxes[i];
            if(status[b]==1){
                dq.push_front(b);
            }
            else dq.push_back(b);
        }
        int ans=0;
        while(!dq.empty()){
            int b=dq.front();
            dq.pop_front();
            if(visited[b]==true)continue;
            if(status[b]==1){
                visited[b]=true;
                ans+=candies[b];
                for(int i=0;i<(int)keys[b].size();i++){
                    int u=keys[b][i];
                    status[u]=1;
                }
                for(int i=0;i<(int)containedBoxes[b].size();i++){
                    int u=containedBoxes[b][i];
                    if(!visited[u]){
                        if(status[u]==1){
                            dq.push_front(u);
                        }else dq.push_back(u);
                    }
                }
            }
        }
        return ans;
    }
};
