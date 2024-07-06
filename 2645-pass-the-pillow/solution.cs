public class Solution {
    public int PassThePillow(int n, int time) {
        time %= (n + n - 2);
        if(time >= n) {
            time -= (n - 1);
            time = n - 1 - time;
        }
        return time + 1;
    }
}
