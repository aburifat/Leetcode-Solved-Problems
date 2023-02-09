public class Solution {
    public int[] PlusOne(int[] digits) {
        int len = digits.Length;
        int carry=1;
        for(int i=len-1;i>=0;i--){
            digits[i] += carry;
            if(digits[i]>9)carry=1;
            else carry = 0;
            digits[i] %= 10;
        }
        if(carry!=0){
            int [] ans = new int[len+1];
            ans[0]=carry;
            for(int i=1;i<=len;i++){
                ans[i]=digits[i-1];
            }
            return ans;
        }
        return digits;
    }
}