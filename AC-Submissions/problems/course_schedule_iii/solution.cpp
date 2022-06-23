class Solution {
    int dp[10010][1010];
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int,vector<int>>pq;
        sort(courses.begin(),courses.end(),cmp);
        int len=courses.size();
        int total_time=0;
        int course_count=0;
        for(int i=0;i<len;i++){
            pq.push(courses[i][0]);
            total_time+=courses[i][0];
            course_count++;
            if(total_time>courses[i][1]){
                total_time-=pq.top();
                pq.pop();
                course_count--;
            }
        }
        return course_count;
    }
};