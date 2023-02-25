class Solution {
public:
    long long MOD = 1e6+33;
    long long base = 63;
    long long POW[10010];
    long long hash[10010];
    void init(){
        POW[0]=1;
        hash[0]=0;
        for(int i=1;i<10010;i++){
            POW[i]=(POW[i-1]*base)%MOD;
            hash[i]=0;
        }
    }
    long long get_hash(string s){
        long long len = s.size();
        long long hs = 0;
        for(int i=len-1;i>=0;i--){
            hs*=base;
            hs+=(s[i]-'a'+1);
            hs%=MOD;
        }
        return hs;
    }
    void init_hash(string s){
        int len=s.size();
        for(int i=len-1;i>=0;i--){
            hash[i]=hash[i+1]*base;
            hash[i]+=(s[i]-'a'+1);
            hash[i]%=MOD;
        }
    }
    long long sub_hash(int l,int r){
        long long hs=hash[l]-(hash[r+1]*POW[r-l+1]);
        if(hs<0){
            long long fx=(-hs)/MOD;
            fx++;
            hs+=(MOD*fx);
        }
        hs%=MOD;
        return hs;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<long long,int>ht;
        init();
        int ct = words.size();
        for(int i=0;i<ct;i++){
            ht[get_hash(words[i])]++;
        }
        init_hash(s);
        int word_len = words[0].size();
        int len = s.size();
        int match_len = word_len*ct;
        vector<int>ans;
        for(int i=0;i<word_len;i++){
            int st=i;
            int now_ct=0;
            unordered_map<long long,int>track;
            for(int j=i;j+word_len<=len;j+=word_len){
                int tmp_len = j-st;
                if(tmp_len>=match_len){
                    long long hs=sub_hash(st,st+word_len-1);
                    track[hs]--;
                    if(track[hs]<ht[hs]){
                        now_ct--;
                    }
                    st+=word_len;
                }
                long long hs2=sub_hash(j,j+word_len-1);
                track[hs2]++;
                if(track[hs2]<=ht[hs2]){
                    now_ct++;
                }
                if(now_ct==ct){
                    ans.push_back(st);
                }
            }
        }
        return ans;
    }
};