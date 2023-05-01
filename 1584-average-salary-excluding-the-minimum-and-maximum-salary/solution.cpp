class Solution {
public:
    int mx=0;
    int mx_ct=0;
    int mn=1e7;
    int mn_ct=0;
    int sum=0;
    int ct=0;
    double average(vector<int>& salary) {
        ct=salary.size();
        for(int i=0;i<(int)salary.size();i++){
            if(salary[i]>mx){
                mx=salary[i];
                mx_ct=1;
            }else if(salary[i]==mx)mx_ct++;
            if(salary[i]<mn){
                mn=salary[i];
                mn_ct=1;
            }else if(salary[i]==mn)mn_ct++;
            sum+=salary[i];
        }
        sum-=(mx*mx_ct);
        ct-=mx_ct;
        if(mx!=mn){
            sum-=(mn*mn_ct);
            ct-=mn_ct;
        }
        double ans=0;
        if(ct!=0)ans=(double)sum/(double)ct;
        return ans;
    }
};
