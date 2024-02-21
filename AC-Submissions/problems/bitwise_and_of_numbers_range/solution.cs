public class Solution {
    public int RangeBitwiseAnd(int left, int right) {
        int rnk = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            rnk++;
        }
        return (left << rnk);
    }
}