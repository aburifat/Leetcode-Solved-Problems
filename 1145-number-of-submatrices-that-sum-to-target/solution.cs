public class Solution {
    public int NumSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        int ans = 0;
        for(int lft = 0; lft < n; lft++){
            int[] sums = new int[m];
            for(int rgt = lft; rgt < n; rgt++){
                for(int i = 0; i < m; i++){
                    sums[i]+=matrix[i][rgt];
                }
                for(int tp = 0; tp < m; tp++){
                    int sum = 0;
                    for(int dn = tp; dn < m; dn++){
                        sum+=sums[dn];
                        if(sum == target){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
}
