class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=(int)nums1.size()+(int)nums2.size();
        vector<int>res(len);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),res.begin());
        double ans;
        if(len%2==0){
            //cout<<len<<" I'm here\n";
            int idx=len/2;
            ans=(double)(res[idx-1]+res[idx]);
            ans/=(2.0);
        }else{
            ans=(double)res[len/2];
        }
        return ans;
    }
};