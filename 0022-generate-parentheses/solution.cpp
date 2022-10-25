class Solution {
    vector<string>ans;
    map<string,int>mp;
public:
    void gen(string s, int l, int r, int n){
        if(l==n&&r==n){
            if(!mp[s]){
                mp[s]++;
                ans.push_back(s);
            }
        }else if(l<=r){
            gen(s+'(',l+1,r,n);
        }else{
            if(l<n)gen(s+'(',l+1,r,n);
            gen(s+')',l,r+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        mp.clear();
        gen("",0,0,n);
        return ans;
    }
};
