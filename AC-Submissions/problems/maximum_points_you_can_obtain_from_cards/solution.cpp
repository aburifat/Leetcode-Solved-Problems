class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len=cardPoints.size();
        int left[len+5],right[len+5];
        for(int i=0;i<len;i++){
            if(i==0)left[i]=cardPoints[i];
            else{
                left[i]=cardPoints[i]+left[i-1];
            }
        }
        for(int i=len-1,j=0;i>=0;i--,j++){
            if(i==len-1)right[j]=cardPoints[i];
            else{
                right[j]=cardPoints[i]+right[j-1];
            }
        }
        int ans=0;
        for(int i=0;i<=k;i++){
            int val=0;
            if(i>0)val+=left[i-1];
            if((k-i)>0)val+=right[k-i-1];
            ans=max(ans,val);
        }
        return ans;
    }
};