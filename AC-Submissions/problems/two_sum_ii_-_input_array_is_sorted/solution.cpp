#include<bits/stdc++.h>
using namespace std;
vector<int>num;
int len;
int blk;

int bs(int l, int r, int k){
    if(l>r)return len+5;
    if(l==r){
        if(l==blk)return len+5;
        if(num[l]==k)return l;
        return len+5;
    }
    int mid=l+(r-l)/2;
    if(num[mid]>=k)return bs(l,mid,k);
    else return bs(mid+1,r,k);
}

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>val;
        num=numbers;
        len=numbers.size();
        for(int i=0;i<len;i++){
            blk=i;
            int ans=bs(0,len-1,target-num[i]);
            if(ans<len){
                i++;
                ans++;
                val.push_back(min(i,ans));
                val.push_back(max(i,ans));
                break;
            }
        }
        return val;
    }
};