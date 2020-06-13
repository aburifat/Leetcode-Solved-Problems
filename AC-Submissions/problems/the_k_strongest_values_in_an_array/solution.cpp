class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int len=arr.size();
        int mid=(len-1)/2;
        int maiden=arr[mid];
        vector<pair<int,int> >st;
        for(int i=0;i<len;i++){
            int dif=abs(arr[i]-maiden);
            st.push_back({dif,arr[i]});
        }
        sort(st.begin(),st.end());
        reverse(st.begin(),st.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(st[i]. second);
        }
        return ans;
    }
};