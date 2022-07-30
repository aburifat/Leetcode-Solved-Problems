class Solution {
public:
    int countPrimes(int n) {
        bool arr[n+5];
        for(int i=2;i<n;i++)arr[i]=true;
        int count=n-2;
        for(long long i=2;i<n;i++){
            if(arr[i]){
                for(long long j=i*i;j<n;j+=i){
                    if(arr[j]){
                        arr[j]=false;
                        count--;
                    }
                }
            }
        }
        if(count<0)count=0;
        return count;
    }
};