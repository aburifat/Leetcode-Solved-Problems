class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int len=security.size();
        int left[len+5],right[len+5];
        for(int i=0;i<len;i++){
            if(i==0)left[i]=0;
            else{
                if(security[i]<=security[i-1]){
                    left[i]=1+left[i-1];
                }else left[i]=0;
            }
        }
        for(int i=len-1;i>=0;i--){
            if(i==len-1)right[i]=0;
            else{
                if(security[i]<=security[i+1]){
                    right[i]=1+right[i+1];
                }else right[i]=0;
            }
        }
        vector<int>ans;
        for(int i=0;i<len;i++){
            if(left[i]>=time&&right[i]>=time)ans.push_back(i);
        }
        return ans;
    }
};
