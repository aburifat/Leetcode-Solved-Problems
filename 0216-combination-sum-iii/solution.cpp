class Solution {
    vector<int>validMasks;
public:
    void init(){
        validMasks.clear();
    }
    int getSum(int mask){
        int sum=0;
        for(int i=0;i<9;i++){
            if(mask&(1<<i)){
                sum+=(i+1);
            }
        }
        return sum;
    }
    void getValidMasks(int mask, int num, int k, int n){
        if(num>9)return;
        if(__builtin_popcount(mask)==k){
            int sum=getSum(mask);
            if(sum==n)validMasks.push_back(mask);
        }else if(__builtin_popcount(mask)<k){
            getValidMasks(mask,num+1,k,n);
            int newMask=mask|(1<<num);
            getValidMasks(newMask,num+1,k,n);
            
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        init();
        vector<vector<int>>ans;
        getValidMasks(0,0,k,n);
        int len=validMasks.size();
        ans.assign(len,vector<int>());
        for(int i=0;i<len;i++){
            for(int j=0;j<9;j++){
                if(validMasks[i]&(1<<j)){
                    ans[i].push_back(j+1);
                }
            }
        }
        return ans;
    }
};
