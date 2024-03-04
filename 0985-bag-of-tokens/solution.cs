public class Solution {
    public int BagOfTokensScore(int[] tokens, int power) {
        Array.Sort(tokens);
        int l = 0, r = tokens.Length - 1;
        int score = 0;
        int mxScore = 0;
        while(l <= r){
            if(tokens[l] <= power){
                power -= tokens[l];
                score++;
                l++;
            }else{
                if(score > 0){
                    power += tokens[r];
                    mxScore = Math.Max(mxScore, score);
                    score--;
                }
                r--;
            }
        }
        return Math.Max(mxScore, score);
    }
}
