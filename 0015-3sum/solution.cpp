class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int ct[200010];
        int inc=1e5;
        for(int i=0;i<200010;i++)ct[i]=0;
        vector<int>v;
        vector<int>tmp(3,0);
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(!ct[nums[i]+inc]){
                v.push_back(nums[i]);
            }
            ct[nums[i]+inc]++;
        }
        sort(v.begin(),v.end());
        len=v.size();
        if(ct[inc]>2)ans.push_back(tmp);
        if(ct[inc]){
            ct[inc]=1;
            for(int i=0;i<len;i++){
                if(v[i]>=0)break;
                if(ct[-v[i]+inc]){
                    tmp[0]=0;
                    tmp[1]=v[i];
                    tmp[2]=-v[i];
                    ans.push_back(tmp);
                }
            }
            ct[inc]=0;
        }
        for(int i=0;i<len;i++){
            if(ct[v[i]+inc]>1){
                int val=-(2*v[i]);
                if(val>=-inc&&val<=inc&&ct[val+inc]){
                    tmp[0]=v[i];
                    tmp[1]=v[i];
                    tmp[2]=val;
                    ans.push_back(tmp);
                }
                ct[v[i]+inc]=1;
            }
        }
        for(int i=0;i<len;i++){
            if(v[i]==0||ct[v[i]+inc]==0)continue;
            ct[v[i]+inc]=0;
            for(int j=i+1;j<len;j++){
                int val=-v[i]-v[j];
                if(v[j]==0||val==0)continue;
                if(val<v[j])continue;
                if(val!=v[i]&&val!=v[j]){
                    if(val>=-inc&&val<=inc&&ct[val+inc]){
                        tmp[0]=v[i];
                        tmp[1]=v[j];
                        tmp[2]=val;
                        ans.push_back(tmp);
                    }
                }
            }
        }
        return ans;
    }
};
