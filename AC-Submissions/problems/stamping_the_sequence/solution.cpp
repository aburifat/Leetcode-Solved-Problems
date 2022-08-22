class Solution {
public:
    bool wildcard(string &sub){
        int len=sub.size();
        for(int i=0;i<len;i++){
            if(sub[i]!='?')return false;
        }
        return true;
    }
    bool match(string &a, string &b){
        if((int)a.size()!=(int)b.size())return false;
        for(int i=0;i<(int)a.size();i++){
            if(a[i]!=b[i]&&a[i]!='?'&&b[i]!='?')return false;
        }
        return true;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n=target.size();
        int m=stamp.size();
        vector<int>ans;
        int ck=1;
        while(ck){
            ck=0;
            for(int i=0;i<n-m+1;i++){
                string sub=target.substr(i,m);
                if(wildcard(sub))continue;
                if(match(stamp,sub)){
                    ck=1;
                    for(int j=0;j<m;j++)target[i+j]='?';
                    ans.push_back(i);
                }
            }
        }
        if(!wildcard(target))ans.clear();
        if((ans.size()>(10*n)))ans.clear();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};