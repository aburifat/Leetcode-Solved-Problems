class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int len=arr.size();
        int ans=0;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                for(int k=j+1;k<len;k++){
                    int val1=abs(arr[i]-arr[j]);
                    int val2=abs(arr[j]-arr[k]);
                    int val3=abs(arr[i]-arr[k]);
                    if(val1<=a&&val2<=b&&val3<=c)ans++;
                }
            }
        }
        return ans;
    }
};
