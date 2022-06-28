class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int len=nums.size();
        int siz=len;
        int ans=0;
        int visited=-1;
        for(int i=0;i<len-1;i++){
            if(nums[i]==nums[i+1]){
                siz--;
                ans++;
            }else{
                i++;
            }
            visited=i;
        }
        visited++;
        ans+=(len-visited);
        return ans;
    }
};