class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i,j;
        for(i=0,j=0;i<m&&j<n;){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        for(int k=i;k<m;k++)ans.push_back(nums1[k]);
        for(int k=j;k<n;k++)ans.push_back(nums2[k]);
        for(i=0;i<(m+n);i++)nums1[i]=ans[i];
    }
};
