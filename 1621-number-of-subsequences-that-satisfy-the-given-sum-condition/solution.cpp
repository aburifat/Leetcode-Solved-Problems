class Solution {
public:
    int mod = 1e9+7;
    vector<int>mem;
    int binExp(int pow){
        if(pow==0)return 1;
        if(pow==1)return 2;
        if(mem[pow]!=-1)return mem[pow];
        if(pow%2==0){
            mem[pow]=(long long)(binExp(pow/2)*(long long)binExp(pow/2))%mod;
        }else{
            mem[pow]=(binExp(pow-1)*2)%mod;
        }
        return mem[pow];
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        mem.assign(len,-1);
        int ans = 0;
        for(int i=0;i<len;i++){
            if(nums[i]>=target)break;
            int val=target-nums[i];
            if(val<nums[i])break;
            int l=i,r=len-1;
            int idx=l;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(nums[mid]<=val){
                    idx=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            int dis=(idx-i);
            int tmp_ct = binExp(dis);
            ans=(ans+tmp_ct)%mod;
        }
        return ans;
    }
};
