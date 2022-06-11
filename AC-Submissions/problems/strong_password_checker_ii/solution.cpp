class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        map<char,int>mp;
        mp['!']=1;
        mp['@']=1;
        mp['#']=1;
        mp['$']=1;
        mp['%']=1;
        mp['^']=1;
        mp['&']=1;
        mp['*']=1;
        mp['(']=1;
        mp[')']=1;
        mp['-']=1;
        mp['+']=1;
        int arr[]={0,0,0,0};
        int len=password.size();
        for(int i=0;i<len;i++){
            if(password[i]<='z'&&password[i]>='a')arr[0]++;
            else if(password[i]<='Z'&&password[i]>='A')arr[1]++;
            else if(password[i]<='9'&&password[i]>='0')arr[2]++;
            else if(mp[password[i]])arr[3]++;
        }
        int ck=0;
        for(int i=1;i<len;i++){
            if(password[i-1]==password[i]){
                ck=1;
                break;
            }
        }
        for(int i=0;i<4;i++){
            if(arr[i]==0){
                ck=1;
                break;
            }
        }
        if(len<8)ck=1;
        if(!ck)return true;
        else return false;
    }
};