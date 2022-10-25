class Solution {
    vector<string>ctSay;
public:
    string goBabe(int n){
        string ans="1";
        for(int i=1;i<n;i++){
            string s="";
            char c;
            int ct=0;
            for(int j=0;j<ans.size();j++){
                if(j==0){
                    ct=1;
                    c=ans[j];
                }else{
                    if(ans[j]==ans[j-1])ct++;
                    else{
                        s+=to_string(ct);
                        s+=c;
                        ct=1;
                        c=ans[j];
                    }
                }
                if(j==(ans.size()-1)){
                    s+=to_string(ct);
                    s+=c;
                }
            }
            ans=s;
        }
        return ans;
    } 
    string countAndSay(int n) {
        return goBabe(n);
    }
};
