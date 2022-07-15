class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mid=n/2;
        for(int l=0;l<=mid;l++){
            int siz=n-l;
            for(int i=l;i<siz-1;i++){
                int tmp=matrix[l][i];
                int x=l;
                int y=i;
                while(1){
                    swap(tmp,matrix[y][n-x-1]);
                    x=n-x-1;
                    swap(x,y);
                    if(x==l&&y==i)break;
                }
                //matrix[x][y]=tmp;
            }
        }
    }
};
