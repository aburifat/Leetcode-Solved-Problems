#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int romanToInt(string s) {
        ll num=0;
        string symb[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        ll vals[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        map<string,ll>idxs;
        ll len=s.size();
        for(ll i=0;i<13;i++){
            idxs[symb[i]]=i+1;
        }
        for(ll i=0;i<len;i++){
            if(i<len-1){
                string tmp="";
                tmp+=s[i];
                tmp+=s[i+1];
                if(idxs[tmp]){
                    num+=vals[idxs[tmp]-1];
                    i++;
                }else{
                    tmp="";
                    tmp=s[i];
                    if(idxs[tmp]){
                        num+=vals[idxs[tmp]-1];
                    }
                }
            }else{
                string tmp="";
                tmp=s[i];
                if(idxs[tmp]){
                    num+=vals[idxs[tmp]-1];
                }
            }
        }
        return num;
    }
};
