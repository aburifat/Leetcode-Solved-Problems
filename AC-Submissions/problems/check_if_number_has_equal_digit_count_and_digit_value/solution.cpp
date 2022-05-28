class Solution {
public:
    bool digitCount(string num) {
        map<int,int>ct,mp;
        int len=num.size();
        for(int i=0;i<len;i++){
            ct[i]=num[i]-'0';
            mp[num[i]-'0']++;
        }
        bool ans=true;
        for(int i=0;i<len;i++){
            if(mp[i]!=ct[i]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};