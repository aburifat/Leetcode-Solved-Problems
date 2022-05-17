class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int ct=0;
        int def=INT_MAX;
        int len=nums.size();
        if(len<3)return ans;
        for(int i=1;i<len;i++){
            if(def==INT_MAX){
                def=nums[i-1]-nums[i];
                ct=2;
            }
            else{
                int tmp=nums[i-1]-nums[i];
                if(def==tmp){
                    ct++;
                    if(i==len-1&&ct>=3){
                        ct-=2;
                        int tmp_ans=ct*(ct+1);
                        tmp_ans/=2;
                        ans+=tmp_ans;
                    }
                }
                else{
                    if(ct>=3){
                        ct-=2;
                        int tmp_ans=ct*(ct+1);
                        tmp_ans/=2;
                        ans+=tmp_ans;
                    }
                    ct=2;
                    def=tmp;
                }
            }
        }
        return ans;
    }
};
