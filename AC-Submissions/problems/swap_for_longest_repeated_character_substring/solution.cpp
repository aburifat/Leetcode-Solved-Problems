class Solution {
public:
    int maxRepOpt1(string text) {
        int len=text.size();
        int left[len+5][30],right[len+5][30],ans[len+5][30],ctCr[30];
        for(int i=0;i<len;i++){
            int cr;
            if(i!=0)cr=text[i-1]-'a';
            for(int j=0;j<26;j++){
                if(i==0)left[i][j]=0;
                else{
                    if(j==cr)left[i][j]=left[i-1][j]+1;
                    else left[i][j]=0;
                }
            }
        }
        for(int i=len-1;i>=0;i--){
            int cr;
            if(i!=len-1)cr=text[i+1]-'a';
            for(int j=0;j<26;j++){
                if(i==len-1)right[i][j]=0;
                else{
                    if(j==cr)right[i][j]=right[i+1][j]+1;
                    else right[i][j]=0;
                }
            }
        }
        for(int i=0;i<30;i++)ctCr[i]=0;
        for(int i=0;i<len;i++){
            int cr=text[i]-'a';
            ctCr[cr]++;
        }
        for(int i=0;i<len;i++){
            int cr=text[i]-'a';
            for(int j=0;j<26;j++){
                int val=left[i][j]+right[i][j];
                if(cr==j)ans[i][j]=val+1;
                else if(val<ctCr[j])ans[i][j]=val+1;
                else if(val==ctCr[j])ans[i][j]=val;
                else if(ctCr[j]) ans[i][j]=1;
                else ans[i][j]=0;
            }
        }
        /*
        for(int j=0;j<26;j++){
            for(int i=0;i<len;i++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return len;
        */
        int val=0;
        for(int j=0;j<26;j++){
            for(int i=0;i<len;i++){
                val=max(val,ans[i][j]);
            }
        }
        return val;
    }
};