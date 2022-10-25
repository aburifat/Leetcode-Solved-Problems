class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==1){
            if(nums[0]==target)return 0;
            else return -1;
        }else if(len==2){
            if(nums[0]==target)return 0;
            else if(nums[1]==target)return 1;
            else return -1;
        }else{
            int idx=-1;
            if(nums[0]<nums[len-1])idx=0;
            else if(nums[len-1]<nums[len-2])idx=len-1;
            else{
                int l=1,r=len-2;
                while(l<=r){
                    if(nums[l]<nums[r]){
                        idx=l;
                        break;
                    }
                    int mid=l+(r-l)/2;
                    if(nums[mid-1]>nums[mid]&&nums[mid+1]>nums[mid]){
                        idx=mid;
                        break;
                    }else if(nums[l]>nums[mid])r=mid-1;
                    else l=mid+1;
                }
            }
            int pos=-1;
            int l=0,r=idx-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]==target){
                    pos=mid;
                    break;
                }else if(nums[mid]>target)r=mid-1;
                else l=mid+1;
            }
            if(pos==-1){
                l=idx,r=len-1;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    if(nums[mid]==target){
                        pos=mid;
                        break;
                    }else if(nums[mid]>target)r=mid-1;
                    else l=mid+1;
                }
            }
            return pos;
        }
    }
};