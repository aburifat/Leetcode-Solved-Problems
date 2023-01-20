class Solution {
    vector<vector<int>>ans;
    map<int,bool>vis;
    map<vector<int>,bool>fuck;
    void go_babe(int mask,vector<int>pre, vector<int>&nums){
        if(pre.size()>1){
            //cout<<mask<<" "<<pre.size()<<" "<<cnt<<"\n";
            vector<int>tmp;
            for(int i=0;i<(int)pre.size();i++)tmp.push_back(nums[pre[i]]);
            if(!fuck[tmp]){
                ans.push_back(tmp);
                fuck[tmp]=true;
            }
        }
        int mn=0;
        if(pre.size()>0)mn=pre[pre.size()-1];
        for(int i=mn;i<(int)nums.size();i++){
            if(pre.size()>0&&nums[i]<nums[pre[pre.size()-1]])continue;
            int newmask=mask|(1<<i);
            if(!vis[newmask]){
                vis[newmask]=true;
                vector<int>newpre=pre;
                newpre.push_back(i);
                go_babe(newmask,newpre,nums);
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vis[0]=true;
        vector<int>emp;
        go_babe(0,emp,nums);
        return ans;
    }
};
