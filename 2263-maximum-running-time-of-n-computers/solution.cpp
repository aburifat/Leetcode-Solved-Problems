class Solution {
public:
    bool isValid(long long mid, vector<int>& b, int n){
        long long mx=mid*n;
        for(int i=0;i<b.size();i++){
            long long val=b[i];
            mx-=min(mid,val);
        }
        if(mx<=0)return true;
        else return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long high=1e14, low=0;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            bool ck=isValid(mid,batteries,n);
            if(ck){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};
