class Solution {
public:
    string orderlyQueue(string s, int k) {
        int len=s.size();
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }else{
            string ans=s;
            for(int i=0;i<len;i++){
                s+=s[0];
                s.erase(s.begin());
                ans = min(ans,s);
            }
            return ans;
        }
    }
};
