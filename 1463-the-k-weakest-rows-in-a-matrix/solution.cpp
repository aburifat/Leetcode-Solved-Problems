class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>v;
        int len=mat.size();
        for(int i=0;i<len;i++){
            int ct=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0)break;
                ct++;
            }
            v.push_back({ct,i});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
