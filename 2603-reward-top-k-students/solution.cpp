class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<string,int>points;
        for(int i=0;i<positive_feedback.size();i++){
            points[positive_feedback[i]]=3;
        }
        for(int i=0;i<negative_feedback.size();i++){
            points[negative_feedback[i]]=-1;
        }
        vector<pair<int,int>>v;
        int len=student_id.size();
        for(int i=0;i<len;i++){
            istringstream is(report[i]);
            string s;
            int val=0;
            while(is >> s){
                val+=points[s];
            }
            v.push_back({val,student_id[i]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(v[i].second);
        return ans;
    }
};
