class Solution {
    vector<vector<int>>nCr;
    int getnCr(int n, int r){
        if(n<=0||r<=0)return 1;
        if(n<r)return 1;
        if(r==1)return n;
        if(nCr[n][r]!=-1)return nCr[n][r];
        return nCr[n][r] = (n*getnCr(n-1,r-1))/r;
    }
public:
    string kthSmallestPath(vector<int>& d, int k) {
        int h=d[1];
        int v=d[0];
        nCr.assign(h+v+1,vector<int>(v+1,-1));
        string ans="";
        while(h&&v){
            int c=getnCr(h+v-1,v);
            if(c<k){
                ans+="V";
                v--;
                k-=c;
            }else{
                ans+="H";
                h--;
            }
        }
        while(h){
            ans+="H";
            h--;
        }
        while(v){
            ans+="V";
            v--;
        }
        return ans;
    }
};
