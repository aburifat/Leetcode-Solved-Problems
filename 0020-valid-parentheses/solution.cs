public class Solution {
    public bool IsValid(string s) {
        Stack<char>st = new Stack<char>();
        int len = s.Length;
        bool ck = true;
        for(int i=0; i<len; i++){
            if(s[i]==')'){
                if(st.Count!=0 && st.Peek()=='(')st.Pop();
                else{
                    ck=false;
                    break;
                }
            }
            else if(st.Count!=0 && s[i]=='}'){
                if(st.Peek()=='{')st.Pop();
                else{
                    ck=false;
                    break;
                }
            }
            else if(st.Count!=0 && s[i]==']'){
                if(st.Peek()=='[')st.Pop();
                else{
                    ck=false;
                    break;
                }
            }
            else st.Push(s[i]);
        }
        if(st.Count!=0)ck = false;
        return ck;
    }
}
