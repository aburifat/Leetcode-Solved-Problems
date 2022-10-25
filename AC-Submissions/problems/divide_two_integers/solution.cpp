class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign=((dividend<0&&divisor<0)||(dividend>=0&&divisor>=0))?true:false;
        if(divisor==1)return dividend;
        bool extra=false;
        if(divisor==INT_MIN){
            if(dividend==INT_MIN)return 1;
            else return 0;
        }
        if(dividend==INT_MIN){
            if(divisor==-1)return INT_MAX;
            else dividend+=abs(divisor);
            extra=true;
        }else if(abs(dividend)<abs(divisor))return 0;
        dividend=abs(dividend);
        divisor=abs(divisor);
        int ck=divisor;
        int ct=0;
        while(ck){
            ck=(ck>>1);
            ct++;
        }
        int ans=0;
        for(int i=31-ct;i>=0;i--){
            if((divisor<<i)<=dividend){
                ans|=(1<<i);
                dividend-=(divisor<<i);
            }
        }
        if(extra)ans++;
        if(!sign)ans=-ans;
        return ans;
    }
};