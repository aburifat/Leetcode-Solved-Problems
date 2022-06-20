class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        int idx;
        if(nums[len-1]<0){
            idx=len;
        }else{
            for(int i=0;i<len;i++){
                if(nums[i]>=0){
                    idx=i;
                    break;
                }
            }
        }
        //cout<<idx<<endl;
        vector<int>arr;
        int i=idx-1,j=idx;
        for(i=idx-1,j=idx;i>=0&&j<len;){
            if(abs(nums[i])<abs(nums[j])){
                arr.push_back((nums[i]*nums[i]));
                i--;
            }else{
                arr.push_back((nums[j]*nums[j]));
                j++;
            }
        }
        
        while(i>=0){
            arr.push_back((nums[i]*nums[i]));
            i--;
        }
        while(j<len){
            arr.push_back((nums[j]*nums[j]));
            j++;
        }
        
        return arr;
    }
};