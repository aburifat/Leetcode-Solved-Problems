class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        bitset<50>bs;
        bs.set();
        bs[0]=0;
        int ct=1,idx=0;
        while(1){
            idx+=((k)*ct);
            idx%=n;
            ct++;
            if(bs[idx]==0)break;
            bs[idx]=0;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(bs[i]==1)ans.push_back(i+1);
        }
        return ans;
    }
};
