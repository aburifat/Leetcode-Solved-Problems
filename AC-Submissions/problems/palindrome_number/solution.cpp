typedef long long ll;
class Solution {
public:
    bool isPalindrome(int x) {
        ll num=x;
        if(num<0)return false;
        ll rev=0;
        ll tmp=num;
        while(tmp){
            rev*=10;
            rev+=(tmp%10);
            tmp/=10;
        }
        if(num==rev)return true;
        else return false;
    }
};