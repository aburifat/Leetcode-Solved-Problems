class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n%2==0){
            if(n==0)break;
            n/=2;
        }
        if(n==1)return true;
        else return false;
    }
};
