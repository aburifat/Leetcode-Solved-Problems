#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v;
        int len=nums.size();
        int idx=len;
        for(int i=0;i<len;i++){
            if(nums[i]>=0){
                idx=i;
                break;
            }
        }
        for(int i=idx,j=idx-1;(i<len)||(j>=0);){
            if(i>=len){
                v.push_back(nums[j]*nums[j]);
                j--;
            }else if(j<0){
                v.push_back(nums[i]*nums[i]);
                i++;
            }else{
                if(abs(nums[i])<=abs(nums[j])){
                    v.push_back(nums[i]*nums[i]);
                    i++;
                }else{
                    v.push_back(nums[j]*nums[j]);
                    j--;
                }
            }
        }
        return v;
    }
};