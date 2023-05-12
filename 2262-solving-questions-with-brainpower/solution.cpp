class Solution {
public:
    vector<long long>mem;
    long long dp(int idx, int len, vector<vector<int>>& ques){
        if(idx>=len)return 0;
        if(mem[idx]!=-1)return mem[idx];
        long long val1 = ques[idx][0] + dp(idx+ques[idx][1]+1,len,ques);
        long long val2 = dp(idx+1,len,ques);
        mem[idx]=max(val1,val2);
        return mem[idx];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int len=questions.size();
        mem.assign(len,-1);
        long long ans=dp(0,len,questions);
        return ans;
    }
};
