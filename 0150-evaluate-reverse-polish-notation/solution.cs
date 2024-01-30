public class Solution {
    private Stack<int> st = new Stack<int>();
    public int EvalRPN(string[] tokens) {
        int len = tokens.Length;
        for(int i = 0; i < len; i++){
            string curr = tokens[i];
            if(curr == "+" || curr == "-" || curr == "*" || curr == "/"){
                int b = st.Peek();
                st.Pop();
                int a = st.Peek();
                st.Pop();
                if(curr == "+"){
                    a+=b;
                }else if(curr == "-"){
                    a-=b;
                }else if(curr == "*"){
                    a*=b;
                }else{
                    if(b!=0){
                        a/=b;
                    }else a=0;
                }
                st.Push(a);
            }else{
                int val;
                if(int.TryParse(curr, out val)){
                    st.Push(val);
                }
            }
        }
        return st.Peek();
    }
}
