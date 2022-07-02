class Solution {
    int mod = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int lenH=horizontalCuts.size();
        int lenV=verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mxH=0;
        for(int i=0;i<lenH;i++){
            if(i==0)mxH=max(mxH,horizontalCuts[i]);
            else mxH=max(mxH,horizontalCuts[i]-horizontalCuts[i-1]);
            if(i==lenH-1)mxH=max(mxH,h-horizontalCuts[i]);
        }
        int mxV=0;
        for(int i=0;i<lenV;i++){
            if(i==0)mxV=max(mxV,verticalCuts[i]);
            else mxV=max(mxV,verticalCuts[i]-verticalCuts[i-1]);
            if(i==lenV-1)mxV=max(mxV,w-verticalCuts[i]);
        }
        long long tmp=mxH%mod;
        tmp=(tmp*(mxV%mod))%mod;
        int ans=tmp;
        return ans;
    }
};