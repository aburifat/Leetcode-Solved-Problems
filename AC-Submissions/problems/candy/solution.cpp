class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        int v[len+5];
        for(int i=0;i<len;i++){
            if(i==0&&i==len-1)v[i]=1;
            else if(i==0&&i<len-1&&ratings[i]<=ratings[i+1])v[i]=1;
            else if(i==len-1&&i>0&&ratings[i]<=ratings[i-1])v[i]=1;
            else if(i>0&&i<len-1&&ratings[i]<=ratings[i-1]&&ratings[i]<=ratings[i+1])v[i]=1;
        }
        for(int i=1;i<len;i++){
            if(ratings[i]>ratings[i-1])v[i]=v[i-1]+1;
        }
        for(int i=len-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])v[i]=v[i+1]+1;
        }
        for(int i=1;i<len;i++){
            if(ratings[i]>ratings[i-1]&&v[i]<=v[i-1])v[i]=v[i-1]+1;
        }
        for(int i=len-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]&&v[i]<=v[i+1])v[i]=v[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<len;i++){
            ans+=v[i];
        }
        return ans;
    }
};