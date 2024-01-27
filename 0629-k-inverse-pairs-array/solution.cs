public class Solution {
    private const int mod = (int)1e9+7;
    public int KInversePairs(int n, int k) {
        int[] prev = new int[k+1];
        int[] curr = new int[k+1];
        prev[0]=curr[0]=1;
        for(int i=1;i<=k;i++){
            prev[i]=curr[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                curr[j]=(prev[j]+(j>0?curr[j-1]:0))%mod;
                curr[j]=(curr[j]+mod-(j>=i?prev[j-i]:0))%mod;
            }
            prev=[..curr];
        }
        return curr[k];
    }
}
