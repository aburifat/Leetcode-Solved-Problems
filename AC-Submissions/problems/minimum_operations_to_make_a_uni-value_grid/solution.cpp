class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=0;
        if(n>0)m=grid[0].size();
        vector<int>v;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
                mp[grid[i][j]]++;
            }
        }
        int len=v.size();
        sort(v.begin(),v.end());
        int idx=len/2;
        int madian=v[idx];
        vector<int>mads;
        mads.push_back(v[idx]);
        if(len%2==0){
            mads.push_back(v[idx-1]);
            madian+=v[idx-1];
            madian/=2;
            if((v[idx]-madian)%x==0&&(madian-v[idx-1])%x==0)mads.push_back(madian);
        }
        int ans=INT_MAX;
        for(int i=0;i<mads.size();i++){
            int dif=0;
            for(int j=0;j<len;j++){
                int tmp=abs(mads[i]-v[j]);
                if(tmp%x==0)dif+=(tmp/x);
                else{
                    dif=INT_MAX;
                    break;
                }
            }
            ans=min(ans,dif);
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};