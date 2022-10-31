class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        vector<bool>ck(len+5,false);
        int pre=-1;
        for(int i=0;i<len;i++){
            if(height[i]>pre){
                pre=height[i];
                ck[i]=true;
            }
        }
        pre=-1;
        for(int i=len-1;i>=0;i--){
            if(height[i]>pre){
                pre=height[i];
                ck[i]=true;
            }
        }
        vector<int>sum;
        for(int i=0;i<len;i++){
            if(i==0)sum.push_back(height[i]);
            else sum.push_back(height[i]+sum[i-1]);
        }
        int l=-1;
        int ans=0;
        for(int i=0;i<len;i++){
            if(ck[i]==true){
                if(l==-1){
                    l=i;
                }else{
                    int water=abs(min(height[i],height[l])*(i-l-1))-abs(sum[i-1]-sum[l]);
                    if(water<0)water=0;
                    ans+=water;
                    l=i;
                }
            }
        }
        return ans;
    }
};
