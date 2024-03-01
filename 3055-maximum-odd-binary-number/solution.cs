public class Solution {
    public string MaximumOddBinaryNumber(string s) {
        int ct = s.Count(ch => ch == '1');
        StringBuilder sb = new();
        sb.Append('1',ct-1);
        sb.Append('0',s.Length - ct);
        sb.Append('1');
        return sb.ToString();
    }
}
