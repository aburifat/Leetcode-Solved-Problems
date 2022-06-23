class Solution {
    vector<vector<int>>adj;
    vector<int>indeg;
    vector<bool>in_stack,visited;
public:
    bool dfs(int s){
        visited[s]=true;
        in_stack[s]=true;
        int len=adj[s].size();
        for(int i=0;i<len;i++){
            int u=adj[s][i];
            if(in_stack[u])return false;
            if(!visited[u]){
                bool ck=dfs(u);
                if(!ck)return ck;
            }
        }
        in_stack[s]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses+5,vector<int>());
        indeg.assign(numCourses+5,0);
        in_stack.assign(numCourses+5,false);
        visited.assign(numCourses+5,false);
        int len=prerequisites.size();
        for(int i=0;i<len;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indeg[prerequisites[i][1]]++;
        }
        vector<int>roots;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0)roots.push_back(i);
        }
        bool ck=true;
        for(int i=0;i<roots.size();i++){
            if(!visited[roots[i]]){
                ck=dfs(roots[i]);
                if(ck==false)break;
            }
        }
        if(ck){
            for(int i=0;i<numCourses;i++){
                if(!visited[i]){
                    ck=dfs(i);
                    if(ck==false)break;
                }
            }
        } 
        return ck;
    }
};