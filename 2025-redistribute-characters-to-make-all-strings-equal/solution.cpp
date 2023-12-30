class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int ct[26];
        memset(ct,0,sizeof(ct));
        for(int i=0;i<n;i++){
            int len = words[i].size();
            for(int j=0;j<len;j++){
                ct[words[i][j]-'a']++;
            }
        }
        bool ck = true;
        for(int i=0;i<26;i++){
            if(ct[i]%n!=0){
                ck=false;
                break;
            }
        }
        return ck;
    }
};
