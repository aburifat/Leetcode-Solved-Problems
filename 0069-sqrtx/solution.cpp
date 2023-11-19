class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x;
        int ans = 0;
        while(l<=r){
            long long mid = l + (r - l) / 2;
            if(mid*mid <= x){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
