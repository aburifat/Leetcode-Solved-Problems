class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        int arr[len+5];
        int maxLen=0;
        for(int i=0;i<len;i++){
            arr[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&arr[i]<arr[j]+1){
                    arr[i]=arr[j]+1;
                }
            }
            maxLen=max(maxLen,arr[i]);
        }
        return maxLen;
    }
};
