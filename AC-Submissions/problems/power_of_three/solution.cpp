class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ck=true;
        if(n==0)ck=false;
        while(n){
            if(n==1)break;
            if(n%3!=0){
                ck=false;
                break;
            }
            n/=3;
        }
        return ck;
    }
};