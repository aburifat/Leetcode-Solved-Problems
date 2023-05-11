class Solution {
public:
    vector<vector<int>>mem;
    int dp(int i, int j, int& len1, int& len2, vector<int>& nums1, vector<int>& nums2){
        if(i>=len1||j>=len2)return 0;
        if(mem[i][j]!=-1)return mem[i][j];
        int val=0;
        if(nums1[i]==nums2[j]){
            val++;
            val+=dp(i+1,j+1,len1,len2,nums1,nums2);
        }else{
            val=dp(i+1,j,len1,len2,nums1,nums2);
            val=max(val,dp(i,j+1,len1,len2,nums1,nums2));
        }
        return mem[i][j]=val;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        mem.assign(len1,vector<int>(len2,-1));
        int ans = dp(0,0,len1,len2,nums1,nums2);
        return ans;
    }
};
