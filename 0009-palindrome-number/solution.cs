public class Solution {
    public bool IsPalindrome(int x) {
        if(x<0)return false;
        long y = 0, tmp = x;
        while(tmp != 0){
            y *= 10;
            y += (tmp%10);
            tmp /= 10;
        }
        return (x==y);
    }
}
