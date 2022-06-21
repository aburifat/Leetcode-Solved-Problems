class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int len=score.size();
        vector<pair<int,int> >v;
        for(int i=0;i<len;i++){
            v.push_back({score[i],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string s[len];
        for(int i=0;i<len;i++){
            int idx=v[i].second;
            if(i==0){
                s[idx]="Gold Medal";
            }else if(i==1){
                s[idx]="Silver Medal";
            }else if(i==2){
                s[idx]="Bronze Medal";
            }else s[idx]=to_string(i+1);
        }
        vector<string>ans;
        for(int i=0;i<len;i++)ans.push_back(s[i]);
        return ans;
    }
};
