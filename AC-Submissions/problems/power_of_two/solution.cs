public class Solution {
    public bool IsPowerOfTwo(int n) {
        bool ck = false;
        while(n > 0){
            if(n%2 == 1){
                if(ck == false) ck = true;
                else return false;
            }
            n /= 2;
        }
        return ck;
    }
}