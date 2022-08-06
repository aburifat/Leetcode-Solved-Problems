class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int turns=minutesToTest/minutesToDie;
        turns++;
        int ct=0;
        int TT=1;
        while(TT<buckets){
            ct++;
            TT*=turns;
        }
        return ct;
    }
};