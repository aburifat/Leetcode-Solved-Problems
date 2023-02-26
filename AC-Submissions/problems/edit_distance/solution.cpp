class Solution {
public:
    int minDistance(string p, string q) {
        int a=p.size();
        int b=q.size();
        int m[a+1][b+1];
        for(int i=0;i<=a;i++)m[i][0]=i;
        for(int i=0;i<=b;i++)m[0][i]=i;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(p[i-1]==q[j-1])m[i][j]=m[i-1][j-1];
                else m[i][j]=1+min(m[i-1][j-1],min(m[i][j-1],m[i-1][j]));
            }
        }
        return m[a][b];
    }
};