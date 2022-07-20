class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>v(30,vector<int>());
        for(int i=0;i<s.size();i++){
            v[s[i]-'a'].push_back(i);
        }
        int len=words.size();
        int ans=0;
        for(int i=0;i<len;i++){
            int nxt=0;
            int siz=words[i].size();
            for(int j=0;j<siz;j++){
                int ch=words[i][j]-'a';
                int it=lower_bound(v[ch].begin(),v[ch].end(),nxt)-v[ch].begin();
                if(it<v[ch].size()&&v[ch][it]<nxt)it++;
                if(it>=v[ch].size()){
                    break;
                }
                if(j==siz-1){
                    ans++;
                }
                nxt=v[ch][it]+1;
            }
        }
        return ans;
    }
};
