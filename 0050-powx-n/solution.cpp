class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0)return 1.0;
        if(n<0)return 1.0 / myPow(x,-n);
        if(n&1) return x * myPow(x*x,(n-1)/2);
        else return myPow(x*x, n/2);
    }
};
