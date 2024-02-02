public class Solution {
    List<int>ans = new List<int>();
    private void Solve(int val, int idx, int low, int high){
        val=(val*10)+idx;
        if(val<=high){
            if(val>=low)ans.Add(val);
            if(idx<9)Solve(val,idx+1,low,high);
        }
    }
    public IList<int> SequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++){
            Solve(0,i,low,high);
        }
        ans.Sort();
        return ans;
    }
}
