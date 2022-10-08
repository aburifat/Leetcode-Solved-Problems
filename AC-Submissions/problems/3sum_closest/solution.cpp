class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=100000;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int val=nums[l]+nums[r]+nums[i];
                if(val==target)return target;
                else{
                    if(abs(ans-target)>abs(val-target))ans=val;
                    (val<target)?l++:r--;
                }
            }
        }
        return ans;
    }
};