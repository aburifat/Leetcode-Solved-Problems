class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=0;
        if(n>0)m=points[0].size();
        long long left[m+5],right[m+5],current[m+5];
        for(int i=0;i<m;i++)current[i]=points[0][i];
        for(int i=1;i<n;i++){
            left[0]=current[0];
            for(int j=1;j<m;j++){
                left[j]=max(left[j-1]-1,current[j]);
            }
            right[m-1]=current[m-1];
            for(int j=m-2;j>=0;j--){
                right[j]=max(right[j+1]-1,current[j]);
            }
            for(int j=0;j<m;j++)current[j]=points[i][j]+max(left[j],right[j]);
        }
        long long ans=LONG_LONG_MIN;
        for(int i=0;i<m;i++)ans=max(ans,current[i]);
        return ans;
    }
};