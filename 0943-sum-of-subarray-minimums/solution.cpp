class Solution {
    const int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int len = arr.size();
        vector<int>lft(len,-1);
        vector<int>rgt(len,len);
        stack<int>st;
        for(int i =0;i<len;i++){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            if(!st.empty())lft[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i =len-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(!st.empty())rgt[i]=st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i=0;i<len;i++){
            ans += (long long)arr[i]%mod*(i-lft[i])%mod*(rgt[i]-i)%mod;
            ans%=mod;
        }
        return static_cast<int>(ans);
    }
};
