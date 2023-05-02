class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCt=0;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]==0){
                return 0;
            }else if(nums[i]<0)negCt++;
        }
        if(negCt%2!=0)return -1;
        return 1;
    }
};
