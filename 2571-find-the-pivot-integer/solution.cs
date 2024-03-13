public class Solution {
    public int PivotInteger(int n) {
        int sum = (n * (n + 1)) / 2;
        int l = 1, r = n;
        int ans = -1;
        while(l<=r)
        {
            int x = l + (r - l) / 2;
            int tmp = (x * (x - 1));
            if(tmp == (sum - x))
            {
                ans = x;
                break;
            }
            else if(tmp < (sum - x))
            {
                l = x + 1;
            }
            else{
                r = x - 1;
            }
        }
        return ans;
    }
}
