class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int len=nums.size();
        int n=len/2;
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>leftsum(n+1,vector<int>()),rightsum(n+1,vector<int>());
        int mx_mask=(1<<n)-1;
        for(int mask=1;mask<=mx_mask;mask++){
            int siz=0;
            int lft=0,rgt=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    lft+=nums[i];
                    rgt+=nums[n+i];
                    siz++;
                }
            }
            leftsum[siz].push_back(lft);
            rightsum[siz].push_back(rgt);
        }
        for(int i=0;i<=n;i++){
            sort(rightsum[i].begin(),rightsum[i].end());
        }
        int ans=min(abs(sum-(2*leftsum[n][0])),abs(sum-(2*rightsum[n][0])));
        for(int siz=1;siz<n;siz++){
            for(auto l:leftsum[siz]){
                int r=(sum-(2*l))/2;
                int sizr=n-siz;
                auto it = lower_bound(rightsum[sizr].begin(),rightsum[sizr].end(),r);
                if(it!=rightsum[sizr].end()){
                    ans=min(ans,abs(sum-(2*(l+(*it)))));
                }
                if(it!=rightsum[sizr].begin()){
                    it--;
                    ans=min(ans,abs(sum-(2*(l+(*it)))));
                }
            }
        }
        return ans;
    }
};