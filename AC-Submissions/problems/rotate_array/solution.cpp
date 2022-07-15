class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        k%=len;
        int jmp=len-k;
        for(int i=0;i<__gcd(len,k);i++){
            int pk=nums[i];
            int j=i;
            while(i!=((j+jmp)%len)){
                nums[j]=nums[(j+jmp)%len];
                j=(j+jmp)%len;
            }
            nums[j]=pk;
        }
    }
};