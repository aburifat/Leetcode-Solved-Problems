class Solution {
    vector<int>ct,tmp;
public:
    void marge(){
        for(int i=0;i<26;i++){
            ct[i]=max(ct[i],tmp[i]);
        }
    }
    bool cmp(){
        bool ck=true;
        for(int i=0;i<26;i++){
            if(tmp[i]<ct[i]){
                ck=false;
                break;
            }
        }
        return ck;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        ct.assign(26,0);
        for(int i=0;i<words2.size();i++){
            tmp.assign(26,0);
            for(int j=0;j<words2[i].size();j++){
                tmp[words2[i][j]-'a']++;
            }
            marge();
        }
        vector<string>ans;
        for(int i=0;i<words1.size();i++){
            tmp.assign(26,0);
            for(int j=0;j<words1[i].size();j++){
                tmp[words1[i][j]-'a']++;
            }
            bool ck=cmp();
            if(ck)ans.push_back(words1[i]);
        }
        return ans;
    }
};
