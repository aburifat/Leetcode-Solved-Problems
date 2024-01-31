public class Solution {
    public int[] DailyTemperatures(int[] temperatures) {
        int len = temperatures.Length;
        int[] ans = new int[len];
        Stack<int> st = new Stack<int>();
        for(int i = len-1; i>=0; i--){
            int mxIdx = i;
            while(st.Count!=0 && temperatures[st.Peek()] <= temperatures[i])st.Pop();
            if(st.Count!=0)mxIdx = st.Peek();
            ans[i] = mxIdx - i;
            st.Push(i);
        }
        return ans;
    }
}
