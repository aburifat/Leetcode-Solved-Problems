class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = n-- + m-- - 1;
        while(len>=0){
            if(n<0)nums1[len--]=nums1[m--];
            else if(m<0)nums1[len--]=nums2[n],n--;
            else if(nums1[m]>nums2[n])nums1[len--]=nums1[m--];
            else nums1[len--]=nums2[n--];
        }
    }
};