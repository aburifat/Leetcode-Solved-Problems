class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool>ck(n+1,false);
        int p=1;
        for(int i=2;i<n;i++)p*=i;
        string s="";
        n--;
        for(int j=n;j>=1;j--){
            int idx=k/p;
            if(k%p!=0)idx++;
            int ct=0;
            for(int i=1;i<=n+1;i++){
                if(ck[i]==false){
                    ct++;
                    if(ct==idx){
                        ck[i]=true;
                        s+=('0'+i);
                        break;
                    }
                }
            }
            k%=p;
            if(k==0)k=p;
            p/=j;
        }
        for(int i=1;i<=n+1;i++){
            if(ck[i]==false){
                s+=('0'+i);
                break;
            }
        }
        return s;
    }
};
