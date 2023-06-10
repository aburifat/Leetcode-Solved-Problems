class Solution {
public:
    int maxValue(int len, int idx, int maxSum) {
        maxSum-=len;
        int l=0,r=maxSum;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long ct = (long long)mid*(long long)mid;
            int x = mid - idx;
            if(x<0)x=0;
            ct-=((long long)x*((long long)x-1)/2);
            int y=mid+idx-len+1;
            if(y<0)y=0;
            ct-=((long long)y*((long long)y-1)/2);
            if(ct<=maxSum){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans++;
        return ans;
    }
};
