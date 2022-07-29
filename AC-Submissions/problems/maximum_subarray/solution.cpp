class Solution {
public:
    int divide(vector<int>& nums, int l, int r){
        if(l>r)return INT_MIN;
        if(l==r)return nums[l];
        int mid=l+(r-l)/2;
        int left,right,sum;
        left=right=sum=nums[mid];
        for(int i=mid-1;i>=l;i--){
            sum+=nums[i];
            left=max(left,sum);
        }
        sum=nums[mid];
        for(int i=mid+1;i<=r;i++){
            sum+=nums[i];
            right=max(right,sum);
        }
        int subSum=max(left+right-nums[mid],max(left,right));
        return max(subSum,max(divide(nums,l,mid-1),divide(nums,mid+1,r)));
    }
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        int ans=divide(nums,0,len-1);
        return ans;
    }
};