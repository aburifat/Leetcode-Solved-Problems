class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm=__gcd(p,q);
        lcm=(p/lcm);
        lcm*=q;
        int x=lcm/q;
        int y=lcm/p;
        x%=2;
        y%=2;
        if(x&&y){
            return 1;
        }else if(x){
            return 0;
        }else if(y){
            return 2;
        }else{
            return -1;
        }
    }
};