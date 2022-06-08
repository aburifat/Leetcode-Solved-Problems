class Solution {
    int nums[110];
public:
    void init(){
        for(int i=0;i<110;i++)nums[i]=-1;
        nums[0]=0;
        nums[1]=1;
    }
    int goBabe(int n){
        if(nums[n]!=-1)return nums[n];
        if(n%2==0)return nums[n]=goBabe(n/2);
        else return nums[n]=goBabe(n/2)+goBabe(n/2+1);
    }
    int getMaximumGenerated(int n) {
        init();
        int ans=0;
        for(int i=0;i<=n;i++){
            if(nums[i]==-1){
                int tmp=goBabe(i);
            }
            ans=max(ans,nums[i]);
        }
        return ans;
    }
};