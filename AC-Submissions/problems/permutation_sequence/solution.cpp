class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        string s="";
        for(int i=1;i<=n;i++)v.push_back(i);
        int ct=1;
        do{
            if(ct==k){
                for(int i=0;i<n;i++){
                    s+=(v[i]+'0');
                }
                break;
            }
            ct++;
        }while(next_permutation(v.begin(),v.end()));
        if(s==""){
            for(int i=0;i<n;i++){
                s+=(v[i]+'0');
            }
        }
        return s;
    }
};