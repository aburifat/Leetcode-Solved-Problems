class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int len = graph.size();
        queue<vector<int>>q;
        map<pair<int,int>,int>mp;
        for(int i=0;i<len;i++){
            int mask=(1<<i);
            vector<int>tmp(3,0);
            tmp[0]=0;
            tmp[1]=i;
            tmp[2]=mask;
            q.push(tmp);
            mp[{i,mask}]++;
        }
        int ans=0;
        while(!q.empty()){
            auto s=q.front();
            q.pop();
            if(s[2]==((1<<len)-1)){
                ans=s[0];
                break;
            }else{
                for(int i=0;i<graph[s[1]].size();i++){
                    int mask=s[2]|(1<<graph[s[1]][i]);
                    if(!mp[{graph[s[1]][i],mask}]){
                        mp[{graph[s[1]][i],mask}]++;
                        vector<int>tmp(3,0);
                        tmp[0]=s[0]+1;
                        tmp[1]=graph[s[1]][i];
                        tmp[2]=mask;
                        q.push(tmp);
                    }
                }
            }
        }
        return ans;
    }
};
