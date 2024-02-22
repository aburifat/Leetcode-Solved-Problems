public class Solution
{
    public int FindJudge(int n, int[][] trust)
    {
        int[] trustCount = new int[n+1];

        for(int i = 0; i < trust.Length; i++)
        {
            trustCount[trust[i][0]]--;
            trustCount[trust[i][1]]++;
        }

        int ans = -1;

        for(int i = 1; i <= n; i++)
        {
            if(trustCount[i] == n-1)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
}