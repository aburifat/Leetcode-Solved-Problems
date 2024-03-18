public class Solution {
    public int FindMinArrowShots(int[][] points) {
        Array.Sort(points, (a, b) => {
            int cmp = a[0].CompareTo(b[0]);
            if(cmp == 0){
                cmp = a[1].CompareTo(b[1]);
            }
            return cmp;
        });
        int ans = 1;
        int[] t = points[0];
        for(int i = 0; i < points.Length; i++) {
            if(t[1] < points[i][0]) {
                ans++;
                t = points[i];
            }
            else {
                t[0] = Math.Max(t[0], points[i][0]);
                t[1] = Math.Min(t[1], points[i][1]);
            }
        }
        return ans;
    }
}
