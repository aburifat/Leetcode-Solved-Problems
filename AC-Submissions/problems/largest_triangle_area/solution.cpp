class Solution {
public:
    double triangeArea(double p[][2]){
        double a=p[0][0];
        a*=(p[1][1]-p[2][1]);
        double b=(double)p[1][0];
        b*=(p[2][1]-p[0][1]);
        double c=(double)p[2][0];
        c*=(p[0][1]-p[1][1]);
        double area=a+b+c;
        area/=(2.0);
        if(area<0)area*=(-1.0);
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int len=points.size();
        double p[len+5][2];
        for(int i=0;i<len;i++){
            for(int j=0;j<2;j++){
                p[i][j]=(double)points[i][j];
            }
        }
        double ans=0;
        double arr[3][2];
        for(int i=0;i<len;i++){
            arr[0][0]=p[i][0];
            arr[0][1]=p[i][1];
            for(int j=i+1;j<len;j++){
                arr[1][0]=p[j][0];
                arr[1][1]=p[j][1];
                for(int k=j+1;k<len;k++){
                    arr[2][0]=p[k][0];
                    arr[2][1]=p[k][1];
                    double area=triangeArea(arr);
                    //cout<<area<<endl;
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};