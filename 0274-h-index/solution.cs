public class Solution {
    public int HIndex(int[] citations) {
        int h = 0;
        Array.Sort(citations);
        int len = citations.Length;
        for(int i = 0; i < citations.Length; i++){
            h = Math.Max(h, Math.Min(len - i, citations[i]));
        }
        return h;
    }
}
