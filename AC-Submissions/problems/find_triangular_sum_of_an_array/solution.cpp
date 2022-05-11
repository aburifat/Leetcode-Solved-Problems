class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int len=nums.size();
        int arr[len+5][len+5];
        for(int i=0;i<len;i++)arr[0][i]=nums[i];
        for(int i=1;i<len;i++){
            for(int j=0;j<(len-i);j++){
                arr[i][j]=arr[i-1][j]+arr[i-1][j+1];
                if(arr[i][j]>9)arr[i][j]%=10;
            }
        }
        return arr[len-1][0];
    }
};