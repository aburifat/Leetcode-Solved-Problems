class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int l=0,r=len-1;
        int area=0;
        while(l<r){
            int tmp=min(height[l],height[r])*(r-l);
            area=max(area,tmp);
            if(height[l]>height[r])r--;
            else l++;
        }
        return area;
    }
};