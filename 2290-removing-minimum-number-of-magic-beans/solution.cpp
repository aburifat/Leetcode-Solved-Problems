class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long len=beans.size();
        sort(beans.begin(),beans.end());
        vector<long long>sum;
        for(long long i=0;i<len;i++){
            if(i==0)sum.push_back(beans[i]);
            else{
                sum.push_back(beans[i]+sum[i-1]);
            }
        }
        long long ans=sum[len-1];
        for(long long i=0;i<len;i++){
            long long dif=0;
            if(i>0)dif=sum[i-1];
            if(i<len-1){
                dif+=abs(sum[len-1]-sum[i]-(beans[i]*(len-i-1)));
            }
            //cout<<i<<" "<<dif<<endl;
            ans=min(ans,dif);
        }
        return ans;
    }
};
