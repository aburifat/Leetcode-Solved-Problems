class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        int l=0,r=len-1;
        int left=-1,right=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                left=mid;
                r=mid-1;
            }else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        l=0,r=len-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                right=mid;
                l=mid+1;
            }else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        vector<int>ans;
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};
