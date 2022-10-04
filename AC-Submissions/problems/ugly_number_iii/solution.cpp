class Solution {
public:
    long long lcm(long long a, long long b){
        a/=__gcd(a,b);
        a*=b;
        return a;
    } 
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l=1,r=2e9,ans=INT_MAX;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long ct=(mid/a)+(mid/b)+(mid/c)-(mid/lcm(a,b))-(mid/lcm(b,c))-(mid/lcm(a,c))+mid/lcm(a,lcm(b,c));
            if(ct>=n){
                ans=min(ans,mid);
                r=mid-1;
            }else l=mid+1;
        }
        return (int)ans;
    }
};