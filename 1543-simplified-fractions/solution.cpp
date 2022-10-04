class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        map<pair<int,int>,bool>mp;
        vector<string>v;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                int gcd=__gcd(j,i);
                if(!mp[{j/gcd,i/gcd}]){
                    mp[{j/gcd,i/gcd}]=true;
                    string s=to_string(j/gcd)+"/"+to_string(i/gcd);
                    v.push_back(s);
                }
            }
        }
        return v;
    }
};
