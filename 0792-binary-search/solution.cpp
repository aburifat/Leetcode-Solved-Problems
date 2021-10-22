#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>v;
int key;

int bs(int l, int r){
    if(l>r)return -1;
    if(l==r){
        if(v[l]==key)return l;
        else return -1;
    }
    int mid=l+(r-l)/2;
    if(v[mid]>=key)return bs(l,mid);
    else return bs(mid+1,r);
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        v=nums;
        key=target;
        int len=nums.size();
        int ans=bs(0,len-1);
        return ans;
    }
};
