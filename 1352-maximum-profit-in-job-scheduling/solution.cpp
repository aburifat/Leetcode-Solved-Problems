class Solution {
    vector<pair<pair<int,int>,int>>job;
    vector<int>dp;
    static bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if(a.first.first == b.first.first){
            if(a.first.second == b.first.second){
                if(a.second>=b.second)return true;
                return false;
            }
            if(a.first.second <= b.first.second) return true;
            return false;
        }
        if(a.first.first <= b.first.first) return true;
        return false;
    }
    int getNext(int val, int n){
        int l = 0, r = n-1;
        int idx = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(job[mid].first.first >= val){
                idx = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return idx;
    }
    int maxProfit(int idx, int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int nxtIdx = getNext(job[idx].first.second,n);
        return dp[idx] = max(maxProfit(idx+1,n), job[idx].second + maxProfit(nxtIdx,n));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        dp.assign(n,-1);
        for(int i=0;i<n;i++){
            job.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(job.begin(),job.end(),cmp);
        int ans = maxProfit(0,n);
        return ans;
    }
};
