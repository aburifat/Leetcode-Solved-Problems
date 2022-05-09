#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto arrStr=strs;
        ll len=arrStr.size();
        string pat=arrStr[0];
        ll ans=LONG_LONG_MAX;
        for(ll i=0;i<len;i++){
            ll ct=0;
            for(ll j=0;j<arrStr[i].size();j++){
                if(pat[j]==arrStr[i][j])ct++;
                else break;
            }
            ans=min(ans,ct);
        }
        string st="";
        for(ll i=0;i<ans;i++)st+=pat[i];
        return st;
    }
};