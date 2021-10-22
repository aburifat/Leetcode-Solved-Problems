// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<bits/stdc++.h>
using namespace std;

int mx;

int bs(int l, int r){
    if(l>r)return mx+5;
    if(l==r){
        if(isBadVersion(l)==false)return mx+5;
        else return l;
    }
    int mid=l+(r-l)/2;
    if(isBadVersion(mid)==true)return min(mid,bs(l,mid));
    else return bs(mid+1,r);
}

class Solution {
public:
    int firstBadVersion(int n) {
        mx=n;
        int ans=bs(1,n);
        return ans;
    }
};