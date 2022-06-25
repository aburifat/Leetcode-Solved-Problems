class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        for(int i=1;i<arr.size()-1;){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                int tmp=0;
                int j=i-1;
                while(j>=0&&arr[j]<arr[j+1]){
                    tmp++;
                    j--;
                }
                tmp++;
                i++;
                while(i<arr.size()&&arr[i]<arr[i-1]){
                    tmp++;
                    i++;
                }
                ans=max(ans,tmp);
            }else i++;
        }
        return ans;
    }
};
