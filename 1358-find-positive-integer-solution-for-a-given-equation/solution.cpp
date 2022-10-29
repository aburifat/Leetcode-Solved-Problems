/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>ans;
        for(int i=1;i<=1000;i++){
            int l=1,r=1000;
            while(l<=r){
                int mid=l+(r-l)/2;
                int val=customfunction.f(i,mid);
                if(val==z){
                    vector<int>tmp;
                    tmp.push_back(i);
                    tmp.push_back(mid);
                    ans.push_back(tmp);
                    break;
                }
                else if(val<z)l=mid+1;
                else r=mid-1;
            }
        }
        return ans;
    }
};
