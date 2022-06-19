class Solution {
    vector<int>idx,ct;
public:
    void margeSort(int l, int r, vector<int>& nums){
        if(l<r){
            int mid=l+(r-l)/2;
            margeSort(l,mid,nums);
            margeSort(mid+1,r,nums);
            vector<int>vals;
            int i=l,j=mid+1;
            for(i=l,j=mid+1;i<=mid&&j<=r;){
                int len=vals.size();
                if(nums[idx[i]]>nums[idx[j]]){
                    vals.push_back(idx[j]);
                    if(len>(j-l))ct[idx[j]]+=abs(len-j+l);
                    j++;
                }else{
                    vals.push_back(idx[i]);
                    if(len>(i-l))ct[idx[i]]+=abs(len-i+l);
                    i++;
                }
            }
            while(i<=mid){
                int len=vals.size();
                vals.push_back(idx[i]);
                if(len>(i-l))ct[idx[i]]+=abs(len-i+l);
                i++;
            }
            while(j<=r){
                int len=vals.size();
                vals.push_back(idx[j]);
                if(len>(j-l))ct[idx[j]]+=abs(len-j+l);
                j++;
            }
            for(int k=0;k<vals.size();k++){
                idx[l+k]=vals[k];
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int len=nums.size();
        idx.clear();
        ct.clear();
        for(int i=0;i<len;i++){
            idx.push_back(i);
            ct.push_back(0);
        }
        margeSort(0,len-1,nums);
        return ct;
    }
};
