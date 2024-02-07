public class Solution {
    public string FrequencySort(string s) {
        List<Tuple<int,char>> charCount = new List<Tuple<int,char>>();

        for(int i = 0; i <= 128; i++){
            charCount.Add(new Tuple<int,char>(0,(char)i));
        }

        for(int i=0;i<s.Length;i++){
            int idx = (int)s[i];
            charCount[idx] = new Tuple<int,char>(charCount[idx].Item1 + 1, charCount[idx].Item2);
        }

        charCount = charCount.OrderByDescending(pair => pair.Item1).ToList();
        
        var stringBuilder = new StringBuilder();
        foreach(var curr in charCount){
            char ch = curr.Item2;
            int ct = curr.Item1;
            if(ct>0)stringBuilder.Append(ch,ct);
        }

        return stringBuilder.ToString();
    }
}
