class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int v1_idx=0,v2_idx=0,w1_idx=0,w2_idx=0;
        int v1_len=word1.size();
        int v2_len=word2.size();
        int w1_len=word1[0].size();
        int w2_len=word2[0].size();
        bool ck=true;
        while(1){
            if(w1_idx>=w1_len){
                v1_idx++;
                w1_idx=0;
                if(v1_idx<v1_len)w1_len=word1[v1_idx].size();
                else w1_len=0;
            }
            if(w2_idx>=w2_len){
                v2_idx++;
                w2_idx=0;
                if(v2_idx<v2_len)w2_len=word2[v2_idx].size();
                else w2_len=0;
            }
            if(v1_idx>=v1_len&&v2_idx>=v2_len)break;
            
            else if(v1_idx>=v1_len||v2_idx>=v2_len){
                ck=false;
                break;
            }
            
            if(word1[v1_idx][w1_idx]!=word2[v2_idx][w2_idx]){
                ck=false;
                break;
            }
            w1_idx++;
            w2_idx++;
        }
        return ck;
    }
};