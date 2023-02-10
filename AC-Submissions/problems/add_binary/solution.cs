public class Solution {
    public string AddBinary(string a, string b) {
        int len=Math.Max(a.Length,b.Length);
        int[] tmp=new int[len];
        int carry=0;
        for(int i=len-1,j=a.Length-1,k=b.Length-1;i>=0;i--,j--,k--){
            tmp[i]+=carry;
            if(j>=0)tmp[i]+=(int)(a[j]-'0');
            if(k>=0)tmp[i]+=(int)(b[k]-'0');
            if(tmp[i]>=2)carry=1;
            else carry=0;
            if(tmp[i]==1||tmp[i]==3)tmp[i]=1;
            else tmp[i]=0;
        }
        char[] ans = new char[len+1];
        ans[0]=(char)(carry+'0');
        for(int i=1;i<=len;i++){
            ans[i]=(char)(tmp[i-1]+'0');
        }
        string s = "";
        if(carry!=0)s=new string(ans,0,len+1);
        else s = new string(ans,1,len);
        return s;
    }
}