#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int key;
int len;

int bs(int l, int r){
    if(l>r)return len+5;
    if(l==r){
        if(v[l]>=key)return l;
        else return len+5;
    }
    int mid=l+(r-l)/2;
    if(v[mid]>=key)return min(mid,bs(l,mid));
    else return bs(mid+1,r);
}

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        v=nums;
        key=target;
        len=v.size();
        int ans=bs(0,len-1);
        if(ans>len)ans=len;
        return ans;
    }
};
