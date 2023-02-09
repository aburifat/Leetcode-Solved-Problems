public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int len = nums.Length;
        int l=0,r=len-1;
        int idx=len;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target){
                idx=mid;
                if(nums[mid]==target)break;
                r=mid-1;
            }else l=mid+1;
        }
        return idx;
    }
}