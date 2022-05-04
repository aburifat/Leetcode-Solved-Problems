class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n=heights.size();
        stack<int>st;
		int left[n+5],right[n+5];
		for(int i=0;i<n;i++){
			while(!st.empty()){
				if(heights[st.top()]>=heights[i])st.pop();
				else break;
			}
			if(st.empty()){
				left[i]=0;
			}else{
				left[i]=(st.top())+1;
			}
			st.push(i);
		}
		while(!st.empty())st.pop();
		for(int i=n-1;i>=0;i--){
			while(!st.empty()){
				if(heights[st.top()]>=heights[i])st.pop();
				else break;
			}
			if(st.empty()){
				right[i]=n-1;
			}else{
				right[i]=(st.top())-1;
			}
			st.push(i);
		}
		for(int i=0;i<n;i++){
			int val=abs(right[i]-left[i])+1;
			val*=heights[i];
			ans=max(ans,val);
		}
        return ans;
    }
};