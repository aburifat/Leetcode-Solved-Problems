class Solution {
public:
    int countSeniors(vector<string>& details) {
        int len=details.size();
        int ans=0;
        for(int i=0;i<len;i++){
            int age=(details[i][11]-'0')*10+(details[i][12]-'0');
            if(age>60)ans++;
        }
        return ans;
    }
};
