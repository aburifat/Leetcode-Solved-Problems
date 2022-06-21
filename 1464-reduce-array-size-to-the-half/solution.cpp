class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int len=arr.size();
        vector<int>v;
        map<int,int>mp;
        for(int i=0;i<len;i++){
            if(!mp[arr[i]])v.push_back(arr[i]);
            mp[arr[i]]++;
        }
        vector<pair<int,int>>val;
        for(int i=0;i<v.size();i++){
            val.push_back({mp[v[i]],v[i]});
        }
        sort(val.begin(),val.end());
        int sum=0;
        int ans=0;
        for(int i=val.size()-1;i>=0;i--){
            sum+=val[i].first;
            ans++;
            if((2*sum)>=len)break;
        }
        return ans;
    }
};
