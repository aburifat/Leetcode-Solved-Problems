class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        if(a.second==b.second){
           if(a.first<b.first) return true;
           else return false;
        }else if(a.second>b.second)return true;
        return false;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int len=plantTime.size();
        vector<pair<int,int>>time;
        for(int i=0;i<len;i++){
            time.push_back({plantTime[i],growTime[i]});
        }
        sort(time.begin(),time.end(),cmp);
        for(int i=0;i<len;i++){
            //cout<<time[i].first<<" "<<time[i].second<<endl;
        }
        int ans=0;
        int st=0;
        for(int i=0;i<len;i++){
            st+=time[i].first;
            ans=max(ans,st+time[i].second);
        }
        return ans;
    }
};