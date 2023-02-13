public class Solution {
    public int CountOdds(int low, int high) {
        int ck = ((low%2)==(high%2))?(low%2==1)?1:0:0;
        return (high-low+1)/2 + ck;
    }
}
