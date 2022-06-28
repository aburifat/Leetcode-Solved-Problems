class Solution {
public:
    void margeSort(int l, int r, int *arr){
        if(l<r){
            int mid=l+(r-l)/2;
            margeSort(l,mid,arr);
            margeSort(mid+1,r,arr);
            int tmp[r-l+1];
            int idx=0;
            int i=l,j=mid+1;
            for(i=l,j=mid+1;i<=mid&&j<=r;){
                if(arr[i]<arr[j]){
                    tmp[idx]=arr[i];
                    i++;
                    idx++;
                }else{
                    tmp[idx]=arr[j];
                    j++;
                    idx++;
                }
            }
            while(i<=mid){
                tmp[idx]=arr[i];
                i++;
                idx++;
            }
            while(j<=r){
                tmp[idx]=arr[j];
                j++;
                idx++;
            }
            for(int i=l;i<=r;i++){
                arr[i]=tmp[i-l];
            }
        }
    }
    int minDeletions(string s) {
        int len=s.size();
        int chCt[26];
        for(int i=0;i<26;i++)chCt[i]=0;
        for(int i=0;i<len;i++)chCt[s[i]-'a']++;
        margeSort(0,25,chCt);
        int ans=0;
        for(int i=1;i<26;i++){
            if(chCt[i]==chCt[i-1]){
                int missing=0;
                if(chCt[0]>0){
                    missing=chCt[0]-1;
                }
                for(int j=i-1;j>=0;j--){
                    if(chCt[j]<(chCt[j+1]-1)){
                        missing=chCt[j+1]-1;
                        break;
                    }
                }
                ans+=abs(chCt[i]-missing);
                chCt[i]=missing;
                margeSort(0,i,chCt);
            }
        }
        return ans;
    }
};