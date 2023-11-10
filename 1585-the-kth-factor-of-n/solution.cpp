class Solution {
public:
    int kthFactor(int n, int k) {
        int sq = sqrt(n);
        for(int i=1;i<=sq;i++) if(n%i==0&&--k==0) return i;
        if(n/sq==sq)sq--;
        for(int i=sq;i>0;i--) if(n%i==0&&--k==0) return n/i;
        return -1;
    }
};
