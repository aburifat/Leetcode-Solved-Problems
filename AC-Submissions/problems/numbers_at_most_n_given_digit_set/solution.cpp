class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int>dgts;
        map<int,int>ckdgt,pos;
        int len=digits.size();
        for(int i=0;i<len;i++){
            if(ckdgt[digits[i][0]-'0']==0){
                ckdgt[digits[i][0]-'0']=1;
                dgts.push_back(digits[i][0]-'0');
            }
        }
        sort(dgts.begin(),dgts.end());
        int mxdgt=dgts[dgts.size()-1];
        int mndgt=dgts[0];
        for(int i=0;i<dgts.size();i++){
            pos[dgts[i]]=i+1;
        }
        int ans;
        vector<int>upNum;
        if(n==0){
            if(ckdgt[0]!=0)ans=1;
            else ans=0;
        }else{
            while(n!=0){
                int tmp=n%10;
                n/=10;
                upNum.push_back(tmp);
            }
            reverse(upNum.begin(),upNum.end());
            ans=0;
            int base=dgts.size();
            len=upNum.size();
            for(int i=0;i<len;i++){
                int tmp=upNum[i];
                if(ckdgt[tmp]==0){
                    if(tmp<mndgt){
                        ans--;
                        ans=(ans*base)+pos[mxdgt];
                        for(int j=i+1;j<len;j++)upNum[j]=mxdgt;
                    }else{
                        for(int j=tmp-1;j>=mndgt;j--){
                            if(ckdgt[j]!=0){
                                ans=(ans*base)+pos[j];
                                break;
                            }
                        }
                        for(int j=i+1;j<len;j++)upNum[j]=mxdgt;
                    }
                }else{
                    ans=(ans*base)+pos[tmp];
                }
            }
        }
        return ans;
    }
};