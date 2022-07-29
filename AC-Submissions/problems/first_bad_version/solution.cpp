// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int BS(int l, int r){
        if(l>r)return INT_MAX;
        int mid=l+(r-l)/2;
        bool ck=isBadVersion(mid);
        if(l==r){
            if(ck)return l;
            else return INT_MAX;
        }
        else if(ck==true){
            return min(mid,BS(l,mid-1));
        }else{
            return BS(mid+1,r);
        }
    }
public:
    int firstBadVersion(int n) {
        int ans=BS(1,n);
        return ans;
    }
};