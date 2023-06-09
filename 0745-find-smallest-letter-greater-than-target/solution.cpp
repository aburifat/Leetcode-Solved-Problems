class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len=letters.size();
        int l=0,r=len-1;
        int idx = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(letters[mid]>target){
                idx=mid;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        return letters[idx];
    }
};
