public class Solution {
    public string SimplifyPath(string path) {
        string[] files = path.Split('/');
        int len = files.Length;
        Stack<string> st = new Stack<string>();
        for(int i=0;i<len;i++){
            if(files[i]=="."||files[i]=="")continue;
            else if(files[i]==".."){
                if(st.Count!=0)st.Pop();
            }
            else st.Push(files[i]);
        }
        string slash = "/";
        StringBuilder sb = new StringBuilder();
        List<string> listfiles = new List<string>();
        while(st.Count!=0){
            listfiles.Add(st.Peek());
            listfiles.Add(slash);
            st.Pop();
        }
        listfiles.Reverse();
        if(listfiles.Count==0)listfiles.Add("/");
        foreach(string file in listfiles){
            sb.Append(file);
        }
        path = sb.ToString();
        return path;
    }
}
