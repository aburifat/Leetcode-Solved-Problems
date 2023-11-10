class Solution {
public:
    int partitionString(string s) {
        long long marker = 0;
        int len = s.size();
        int ans = 1;
        for(int i=0;i<len;i++){
            int ch = s[i]-'a';
            if(marker & (1<<ch)){
                ans++;
                marker=0;
            }
            marker|=(1<<ch);
        }
        return ans;
    }
};
