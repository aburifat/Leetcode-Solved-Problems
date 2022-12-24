class Solution {
public:
    int captureForts(vector<int>& forts) {
        int len=forts.size();
        int mxans=0;
        bool ck=false;
        int ct=0;
        for(int i=0;i<len;i++){
            if(forts[i]==1){
                ck=true;
                ct=0;
            }else if(forts[i]==-1){
                ck=false;
                mxans=max(mxans,ct);
                ct=0;
            }else if(ck==true)ct++;
        }
        ck=false;
        ct=0;
        for(int i=len-1;i>=0;i--){
            if(forts[i]==1){
                ck=true;
                ct=0;
            }else if(forts[i]==-1){
                ck=false;
                mxans=max(mxans,ct);
                ct=0;
            }else if(ck==true)ct++;
        }
        return mxans;
    }
};
