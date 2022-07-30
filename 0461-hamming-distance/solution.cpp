class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis=0;
        for(int i=0;i<32;i++){
            int ck=(1<<i);
            if((ck&x)!=(ck&y))dis++;
        }
        return dis;
    }
};
